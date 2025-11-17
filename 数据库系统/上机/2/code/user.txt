-- 在branch_manager_user用户下
-- 激活角色
set role branch_manager;
use bank019;
-- 测试
mysql> insert into branch values
    -> ('Brighton1111','Brooklyn111',71000001);

UPDATE branch
SET assets = 114514
WHERE branch_name = 'Brighton1111';

delete from branch
where assets = 114514;