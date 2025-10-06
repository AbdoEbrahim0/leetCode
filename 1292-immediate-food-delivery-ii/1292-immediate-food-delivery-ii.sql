/* Write your T-SQL query statement below */
with cte as(
select *, dense_rank() over (partition by customer_id  order by customer_id,order_date) as drnk
from Delivery

)

select round (100.0*sum (case when order_date=customer_pref_delivery_date then 1 else 0 end )/count(*) ,2)  as immediate_percentage
from cte
where drnk=1