/* Write your T-SQL query statement below */
-- i get a problem in repeting MAsk movie in products cell so try to filter it before using table
-- select sell_date ,count(distinct product) as num_sold , 
-- string_agg( product ,',') within group (order by product) as products
-- from Activities
-- group by sell_date
-- order by sell_date;

with temp as (
select distinct sell_date,product
from Activities
)

select sell_date ,count(distinct product) as num_sold , 
string_agg( product ,',') within group (order by product) as products
from temp
group by sell_date
order by sell_date;
