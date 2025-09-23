/* Write your T-SQL query statement below */

--[maxFn]
-- select distinct max(salary) as  SecondHighestSalary 
-- from Employee
-- where salary < (select max(salary) from Employee); 

-- [subQuery]
-- processes queries in this order:
-- FROM
-- WHERE
-- GROUP BY
-- HAVING
-- SELECT
-- ORDER BY
-- select salary as
-- from (
-- select id,salary,row_number() over(order by salary desc)  as rn
-- from Employee 
-- ) AS ranked --note it will not work if As ranked not used
-- where rn =2 ;

with RankedSalaries as (
  select  salary, dense_rank() over (order by salary desc) as rn
  from Employee
)
select 
    case 
    when max(rn)=1 then null
    else MAX(CASE WHEN rn = 2 THEN salary END)
    end
    as  SecondHighestSalary 
from RankedSalaries

;



--   select distinct salary, row_number() over (order by salary desc) as rn
--   from Employee
--   output:
--   | salary | rn |
-- | ------ | -- |
-- | 100    | 1  |
-- | 100    | 2  |