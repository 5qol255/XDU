# 创建函数为所有存款账户增加1%的利息
-- 使用 DELIMITER $$ 临时更改语句结束符
DELIMITER $$
-- 允许创建函数
SET GLOBAL log_bin_trust_function_creators = 1;
-- 创建函数
CREATE FUNCTION add_interest() RETURNS INT
MODIFIES SQL DATA
BEGIN
  UPDATE account SET balance = balance * 1.01;
  RETURN ROW_COUNT();
END$$
DELIMITER ;

-- 执行函数
select add_interest();


# 创建新表branch_total和触发器
-- 创建 branch_total 表
CREATE TABLE branch_total (
  branch_name CHAR(30) NOT NULL,
  total_balance DECIMAL(12),
  PRIMARY KEY (branch_name),
  FOREIGN KEY (branch_name) REFERENCES branch(branch_name)
);

-- 填充初始数据
INSERT INTO branch_total (branch_name, total_balance)
SELECT branch_name, SUM(balance)
FROM account
GROUP BY branch_name;

-- 创建 INSERT 触发器
DELIMITER $$
CREATE TRIGGER after_account_insert
AFTER INSERT ON account
FOR EACH ROW
BEGIN
  UPDATE branch_total
  SET total_balance = total_balance + NEW.balance
  WHERE branch_name = NEW.branch_name;
  
  INSERT INTO branch_total(branch_name, total_balance)
  SELECT NEW.branch_name, NEW.balance
  WHERE NOT EXISTS (SELECT 1 FROM branch_total WHERE branch_name = NEW.branch_name);
END$$
DELIMITER ;

-- 创建 DELETE 触发器
DELIMITER $$
CREATE TRIGGER after_account_delete
AFTER DELETE ON account
FOR EACH ROW
BEGIN
  UPDATE branch_total
  SET total_balance = total_balance - OLD.balance
  WHERE branch_name = OLD.branch_name;
END$$
DELIMITER ;

-- 创建 UPDATE 触发器
DELIMITER $$
CREATE TRIGGER after_account_update
AFTER UPDATE ON account
FOR EACH ROW
BEGIN
  IF OLD.branch_name = NEW.branch_name THEN
    UPDATE branch_total
    SET total_balance = total_balance + (NEW.balance - OLD.balance)
    WHERE branch_name = NEW.branch_name;
  ELSE
    -- 支行名称发生变化
    UPDATE branch_total
    SET total_balance = total_balance - OLD.balance
    WHERE branch_name = OLD.branch_name;
    
    UPDATE branch_total
    SET total_balance = total_balance + NEW.balance
    WHERE branch_name = NEW.branch_name;
    
    INSERT INTO branch_total (branch_name, total_balance)
    SELECT NEW.branch_name, NEW.balance
    WHERE NOT EXISTS (SELECT 1 FROM branch_total WHERE branch_name = NEW.branch_name);
  END IF;
END$$
DELIMITER ;