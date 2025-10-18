/* Write your T-SQL query statement below */
-- select e.name
-- from Employee as e  join Employee as m
-- on m.managerId =e.id 

select e.name as Employee
from Employee as e
where e.Salary >(select m.Salary from Employee as m where m.id=e.managerId  )
