/* Write your T-SQL query statement below */
--  and (select 1 from Employees as e2 where e1.employee_id   );

select e1.employee_id from Employees e1 
where   e1.salary <30000 and  e1.manager_id not  in 
 (select e2.employee_id from Employees as e2)
 order by e1.employee_id;
 