/* Write your T-SQL query statement below */
-- select customer_id
-- from Customer 
-- where Customer.product_key in (select product_key from Product );

select customer_id 
from Customer 
group by customer_id 
having count( distinct product_key) = (select count(product_key) from Product );
