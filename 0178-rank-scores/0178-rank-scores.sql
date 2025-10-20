/* Write your T-SQL query statement below */
-- with cte as (


-- )
 
--  select *
--  from cte

 select score, dense_rank() over (order by score Desc) as rank
from Scores