/* Write your T-SQL query statement below */
-- select d.name as Department ,e.name,e.salary
-- from Department as d join Employee as e
-- on d.id=e.departmentId
-- group by d.name,e.name,e.salary
-- having e.salary =(select max(salary) from Employee where departmentId =d.id)

-- with cte as(
    
-- select departmentId ,max(salary) as MaximumSal
-- from Employee
-- group by departmentId
-- )


-- select  d.name as Department , e.name as Employee ,e.salary as Salary
-- from Department as d ,Employee as e
-- where d.id=cte.departmentId and e.salary =cte.MaximumSal

--[join & SubQuerey]
-- select d.name as Department ,e.name as Employee,e.salary as Salary 
-- from Department as d join Employee as e
-- on d.id=e.departmentId
-- where e.salary =( select max(salary) from Employee  where  departmentId=d.id )

select d.name as Department ,e.name as Employee,e.salary as Salary 
from Department as d join Employee as e
on d.id=e.departmentId
where e.salary =( select max(salary) from Employee  group by  departmentId having departmentId=d.id)