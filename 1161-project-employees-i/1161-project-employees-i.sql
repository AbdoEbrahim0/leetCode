/* Write your T-SQL query statement below */
select project_id  ,
cast(sum(e.experience_years) *1.0 /count(p.project_id)  as decimal(10,2)) as average_years
from Project as p join Employee as e
on p.employee_id =e.employee_id
where p.employee_id =e.employee_id
group by p.project_id  ;
