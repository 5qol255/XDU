# 建库
create database employee3_20;
# 切換至employee3_20
use employee3_20;
## 建表employee
create table employee(
employee_name char(30) not null,
street char(30),
city char (30),
primary key(employee_name)
);
## 插入数据employee
insert into emploYEE Values
('John Smith', 'Maple Street 15', 'New York'),
('Emily Davis', 'Oak Avenue 22', 'Los Angeles'),
('Michael Brown', 'Pine Road 30', 'Chicago'),
('Sarah Wilson', 'Cedar Lane 45', 'Houston'),
('David Taylor', 'Birch Court 60', 'Phoenix'),
('Jones', 'Main Street 10', 'Boston'),
('Emma Johnson', 'Elm Drive 78', 'New York');
## 建表company
create table company(
company_name char(30) not NULL,
city char (30),
primary key(company_name)
);
## 插入数据company
INSERT inTO company VALUEs
('Acme Technology Solutions', 'San Francisco'),
('Goldman Sachs Investment Bank', 'New York'),
('McKinsey & Company Consulting', 'Chicago'),
('Walmart Retail Operations', 'Bentonville'),
('Ford Motor Company Engineering', 'Dearborn'),
('CNN Media Productions', 'Atlanta'),
('Microsoft Cloud Division', 'Redmond'),
('JPMorgan Chase Finance', 'Boston'),
('First Bank Corporation', 'New York'),
('Small Bank Corporation', 'Chicago');
## 建表works
create table works(
employee_name char(30) not null,
company_name char(30) not null,
salary decimal(12,2),
primary key(employee_name),
FOREIGN KEY (employee_name) REFERENCES employee(employee_name),
FOREIGN KEY(company_name) REFERENCES company(company_name)
);
## 插入数据works
INSERT INTO works VALUES
('John Smith', 'Acme Technology Solutions', 78500.00),
('Emily Davis', 'Goldman Sachs Investment Bank', 92000.00),
('Michael Brown', 'McKinsey & Company Consulting', 81000.00),
('Sarah Wilson', 'Walmart Retail Operations', 62000.00),
('David Taylor', 'Ford Motor Company Engineering', 73500.00),
('Jones', 'First Bank Corporation', 80000.00),
('Emma Johnson', 'CNN Media Productions', 58000.00);
## 建表manages
create table manages(
employee_name char(30)not null,
manager_name char(30)not null,
primary key(employee_name),
FOREIGN KEY (employee_name) REFERENCES employee(employee_name)
);
## 插入数据manages
insert into manages values
('John Smith', 'Michael Brown'),
('Emily Davis', 'Michael Brown'),
('Sarah Wilson', 'Emily Davis'),
('David Taylor', 'John Smith'),
('Jones','Emily Davis'),
('Emma Johnson', 'Sarah Wilson');
-- 查询a
SELECT employee.employee_name, employee.city
FROM employee JOIN works ON employee.employee_name = works.employee_name
WHERE works.company_name = 'First Bank Corporation';
-- 查询b
select employee.employee_name, employee.street, employee.city
from employee join works on employee.employee_name = works.employee_name
where works.company_name = 'First Bank Corporation' and works.salary > 10000;
-- c
SELECT employee.employee_name
FROM employee JOIN works ON employee.employee_name = works.employee_name
WHERE not works.company_name = 'First Bank Corporation';
-- d
SELECT employee.employee_name
FROM employee JOIN works ON employee.employee_name = works.employee_name
WHERE works.salary > 
(select max(salary) from works where company_name = 'Small Bank Corporation');
-- e
select city from company
where city in(
    select city from company
    where company_name = 'Small Bank Corporation'
);
-- f
SELECT company_name, COUNT(employee_name) AS employee_count
FROM works
GROUP BY company_name
HAVING employee_count = (
    SELECT MAX(emp_count)
    FROM (
        SELECT COUNT(employee_name) AS emp_count
        FROM works
        GROUP BY company_name
    ) AS temp
);
-- g
SELECT company_name/*AVG(salary) AS average_salary*/
FROM works
where
    not company_name = 'First Bank Corporation' and
    salary > (
        select avg(salary) from works
        where company_name = 'First Bank Corporation'
    );
/*GROUP BY company_name*/
-- 3.10 a
update employee
set city = 'Newtown'
where employee_name = 'Jones';
-- 3.10 b
update works
join manages on manages.manager_name = works.employee_name
set salary = if(salary*1.1<100000,salary*1.1,salary*1.03)
where company_name = 'First Bank Corporation';