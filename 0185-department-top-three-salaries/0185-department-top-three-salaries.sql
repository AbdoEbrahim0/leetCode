/* Write your T-SQL query statement below */
-- select top 3 d.name as Department , e.name as Employee , e.Salary as Salary
-- from Department as d left join  Employee as e
-- on d.id =e.departmentId 

-- order by e.Salary
-- ;

-- select distinct top 3 departmentId , salary 
-- from Employee
-- group by departmentId , salary
-- order by departmentId,salary desc

-- with cte as (
-- select  departmentId , salary ,dense_rank() over (partition by  departmentId order by departmentId,salary desc ) as rnk
-- from Employee
-- )
-- select *
-- from cte


with cte as (
select d.name as Department, e.name as Employee , salary as Salary ,dense_rank() over (partition by  departmentId order by departmentId,salary desc ) as rnk
from Employee as e
join Department as d
on e.departmentId = d.id
)
select  Department, Employee ,Salary
from cte
where rnk<=3
