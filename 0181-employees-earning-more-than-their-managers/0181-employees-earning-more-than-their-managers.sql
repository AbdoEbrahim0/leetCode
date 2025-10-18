/* Write your T-SQL query statement below */
select e.name as Employee
from Employee as e
where e.managerId is not null  and e.Salary >(select m.Salary from Employee as m where  m.id=e.managerId  )

-- select e.name as Employee
-- from Employee as e
-- where e.Salary >(select m.Salary from Employee as m where e.managerId is not null and m.id=e.managerId  )

