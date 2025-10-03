/* Write your T-SQL query statement below */
with cte as (
select product_id ,
       new_price ,
       dense_rank() over 
       (PARTITION BY product_id order by change_date desc) as drnk
from Products
where change_date <= '2019-8-16'
) 
select product_id , new_price as price from cte
where drnk=1
union 
select product_id, new_price = 10
from  Products 
where product_id not in( select product_id from cte) 