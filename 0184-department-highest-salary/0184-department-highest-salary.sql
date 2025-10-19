/* Write your T-SQL query statement below */

--[TWO join & SubQuerey and where]

-- select d.name as Department ,e.name as Employee,e.salary as Salary 
-- from Department as d join Employee as e
-- on d.id=e.departmentId
-- where e.salary =( select max(salary) from Employee  where  departmentId=d.id )

--[TWO join & SubQuerey and group by having]

-- select d.name as Department ,e.name as Employee,e.salary as Salary 
-- from Department as d join Employee as e
-- on d.id=e.departmentId
-- where e.salary =( select max(salary) from Employee  group by  departmentId having departmentId=d.id)


--[3 join & CTE ]
with cte as(
    
select departmentId ,max(salary) as MaximumSal
from Employee
group by departmentId
)
select d.name as Department ,e.name as Employee,e.salary as Salary 
from  Employee as e
 join Department as d
on e.departmentId=d.id
 join cte 
 on e.salary =cte.MaximumSal and cte.departmentId= e.departmentId

