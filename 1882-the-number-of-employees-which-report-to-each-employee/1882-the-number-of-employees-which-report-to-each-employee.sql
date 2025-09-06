-- /* Write your T-SQL query statement below */
-- wrong approach if you used  count(e1.reports_to) as reports_count ,avg(e1.age) as  average_age 
select e1.employee_id AS employee_id , e1.name , count(e2.reports_to) as reports_count ,
round(avg(e2.age*1.0)  ,0)  as average_age 
from Employees as e1 
join Employees as e2 
on e1.employee_id   =e2.reports_to

group by e1.employee_id,e1.name
ORDER BY e1.employee_id;
/* Write your T-SQL query statement below */
-- select employee_id  , name , count(reports_to) as reports_count ,avg(age) as  average_age 
-- from Employees 
-- -- as e1 
-- -- join Employees as e2 
-- -- on e1.employee_id   =e2.reports_to
-- where  employee_id   =reports_to
-- group by employee_id, name;