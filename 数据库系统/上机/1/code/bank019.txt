# 建库
create database bank019;
# 切换
use bank019;
# 建表
create table branch(
branch_name char(30) NOT NULL,
branch_city char(30),
assets decimal(12),
primary key(branch_name)
);
# 写数据
insert into branch values
('Brighton','Brooklyn',7100000),
('Downtown','Brooklyn',9000000),
('Mianus','Horseneck',400000),
('North Town','Rye',3700000),
('Perryridge','Horseneck',1700000),
('Pownal','Bennington',300000),
('Redwood','Palo Alto',2100000),
('Round Hill','Horseneck',8000000);
# 建表
create table account (
account_number char(10),
branch_name char(30) NOT NULL,
balance decimal(12),
PRIMARY KEY (account_number),
FOREIGN KEY (branch_name) REFERENCES branch(branch_name), 
CONSTRAINT chk_balance CHECK (balance >= 0 )
);
# 写数据
insert into account values
('A-101','Downtown',500),
('A-102','Perryridge',400),
('A-201','Brighton',900),
('A-215','Mianus',700),
('A-217','Brighton',750),
('A-222','Redwood',700),
('A-305','Round Hill',350);
# 建表
create table customer(
customer_name char(30),
customer_street char(30),
customer_city char(30),
primary key(customer_name)
);
# 写数据
insert into customer values
('Adams','Spring','Pittsfield'),
('Brooks','Senator','Brooklyn'),
('Curry','North','Rye'),
('Glenn','Sand Hill','Woodside'),
('Green','Walnut','Stamford'),
('Hayes','Main','Harrison'),
('Johnson','Alma','Palo Alto'),
('Jones','Main','Harrison'),
('Lindsay','Park','Pittsfield'),
('Smith','North','Rye'),
('Turner','Putnam','Stamford'),
('Williams','Nassau','Princeton');
# 建表
create table depositor(
customer_name char(30),
account_number char(10),
FOREIGN KEY (customer_name) REFERENCES customer(customer_name), 
FOREIGN KEY (account_number) REFERENCES account(account_number)
);
# 写数据
insert into depositor values
('Hayes','A-102'),
('Johnson','A-101'),
('Johnson','A-201'),
('Jones','A-217'),
('Lindsay','A-222'),
('Smith','A-215'),
('Turner','A-305');
# 建表
create table loan(
loan_number char(30),
branch_name char(30),
amount int,
primary key(loan_number),
FOREIGN KEY (branch_name) REFERENCES branch(branch_name) 
);
# 写数据
insert into loan values
('L-11','Round Hill',900),
('L-14','Downtown',1500),
('L-15','Perryridge',1500),
('L-16','Perryridge',1300),
('L-17','Downtown',1000),
('L-23','Redwood',2000),
('L-93','Mianus',500);
# 建表
create table borrower(
customer_name char(30),
loan_number char(30),
FOREIGN KEY (loan_number) REFERENCES loan(loan_number),
FOREIGN KEY (customer_name) REFERENCES customer(customer_name)
);
# 写数据
insert into borrower values
('Adams','L-16'),
('Curry','L-93'),
('Hayes','L-15'),
('Jones','L-17'),
('Smith','L-11'),
('Smith','L-23'),
('Williams','L-17');
insert into customer values
('Jackson',null,null);
insert into borrower values
('Jackson','L-14');
