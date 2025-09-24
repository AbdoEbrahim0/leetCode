/* Write your T-SQL query statement below */
-- declare @sum int
-- with ModifiedbyTurnOrder as
-- (
-- select  person_name,turn,sum(weight) over (order by turn) as acc 
-- from Queue
-- )
-- select top 1 person_name
-- from ModifiedbyTurnOrder    
-- where acc<=1000 
-- order by turn Desc
-- ;

with ModifiedbyTurnOrder as
(
select  sum(weight) over (order by turn) as acc 
from Queue
)
select person_name
from Queue
where turn= (select count(*) from ModifiedbyTurnOrder  where acc<=1000 )
;



