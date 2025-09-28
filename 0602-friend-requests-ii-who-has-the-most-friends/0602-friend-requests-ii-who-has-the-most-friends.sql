/* Write your T-SQL query statement below */


--[CTE]
-- ########
-- with cte as (
-- select accepter_id as id
-- from RequestAccepted
-- union all
-- select  requester_id
-- from RequestAccepted
-- )

-- select top 1 id ,count(id) as num
-- from cte
-- group by id
-- order by num desc;


--[subQuery]

select top 1 id ,count(id) as num
from 
(
select accepter_id as id
from RequestAccepted
union all
select  requester_id as id
from RequestAccepted

) as allFirndsOnce --must make alies to table to work if not doing it you will get syntax error 
group by id
order by num desc;