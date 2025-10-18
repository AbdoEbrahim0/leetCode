/* Write your T-SQL query statement below */

-- --[SubQuery  Less efficient]
-- select e.name as Employee
-- from Employee as e
-- where e.Salary >(select m.Salary from Employee as m where e.managerId is not null and m.id=e.managerId  )

-- --[SubQuery  More efficient]
-- select e.name as Employee
-- from Employee as e
-- where e.managerId is not null  and e.Salary >(select m.Salary from Employee as m where  m.id=e.managerId  )

--[self join with note solving missunderstanding]
-- select e.name Employee
-- from Employee e join Employee m
-- on e.id=m.managerId and e.salary>m.salary

/*
Translation : finds managers who earn more than their employees.
“Find employees (e) whose ID matches the managerId of someone else (m).”
You're treating e as the manager, and m as the employee.

| Employee |
| -------- |
| Max      |
*/
--[self join with note solving missunderstanding]

select e.name Employee
from  Employee m join Employee e 
on m.id=e.managerId and e.salary>m.salary

/*
Translation: employees who earn more than their managers.
“Find employees (e) whose manager’s ID matches m.id.”
You're treating e as the employee, and m as the manager.

| Employee |
| -------- |
| Joe     |
*/