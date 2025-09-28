/* Write your T-SQL query statement below */

with cte as (
select accepter_id as id
from RequestAccepted
union all
select  requester_id
from RequestAccepted
)

select top 1 id ,count(id) as num
from cte
group by id
order by num desc;




-- select top 1 accepter_id as id,count(accepter_id)+count(requester_id)-1  as num
-- from RequestAccepted
-- group by accepter_id
-- order by  num desc;


-- select  requester_id,count( requester_id) as cntSender
-- from RequestAccepted
-- group by  requester_id
-- order by  cntSender desc;


-- select  requester_id, accepter_id ,count( requester_id) as cntSender ,count(accepter_id) as cntReciver
-- from RequestAccepted
-- group by  requester_id,accepter_id
-- order by  cntSender,cntReciver desc;