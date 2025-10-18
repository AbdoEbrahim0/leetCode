/* Write your T-SQL query statement below */

-- --[SubQuery  Less efficient]
-- select e.name as Employee
-- from Employee as e
-- where e.Salary >(select m.Salary from Employee as m where e.managerId is not null and m.id=e.managerId  )

-- --[SubQuery  More efficient]
-- select e.name as Employee
-- from Employee as e
-- where e.managerId is not null  and e.Salary >(select m.Salary from Employee as m where  m.id=e.managerId  )

-- select e.name Employee
-- from Employee e join Employee m
-- on e.id=m.managerId 
/*
| Employee |
| -------- |
| Sam      |
| Max      |
*/
select e.name Employee
from Employee e join Employee m
on m.id=e.managerId and e.salary>m.salary
