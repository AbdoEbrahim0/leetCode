/* Write your T-SQL query statement below */
-- wrong 
-- select e.name , b.bonus from Employee as e left join Bonus as b on e.empId = b.empId and  b.bonus <1000;
-- correct 
select e.name , b.bonus from Employee as e left join Bonus as b on e.empId = b.empId where  b.bonus <1000 or b.bonus is null;