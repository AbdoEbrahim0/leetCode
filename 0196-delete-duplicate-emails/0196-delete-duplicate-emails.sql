/* Write your T-SQL query statement below */
with duplicated as(
select *, dense_rank() over (partition by email order by id ) as drnk 
from Person
)
delete  from Person 
where id in (
    select id from duplicated where drnk>1
);