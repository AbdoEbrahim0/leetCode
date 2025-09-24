/* Write your T-SQL query statement below */
-- declare @sum int
with ModifiedbyTurnOrder as
(
select  *,sum(weight) over (order by turn) as acc 
from Queue
)
-- select @sum=weight+@sum
-- from Modified;
select top 1 person_name
from ModifiedbyTurnOrder    
where acc<=1000 
order by turn Desc
;



