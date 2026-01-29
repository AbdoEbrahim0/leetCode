/* Write your T-SQL query statement below */
-- select p.product_id ,avg(p.price *u.units)as average_price from Prices as p join UnitsSold as u on 
-- u.product_id = p.product_id
-- where 
-- u.purchase_date < p.end_date and  u.purchase_date > start_date;
-- SELECT 
--   p.product_id,
--   ISNULL(ROUND(SUM(CAST(p.price * u.units AS FLOAT)) / NULLIF(SUM(u.units), 0), 2), 0) AS average_price
-- FROM 
--   Prices p
-- LEFT JOIN 
--   UnitsSold u 
--   ON p.product_id = u.product_id 
--   and  u.purchase_date BETWEEN p.start_date AND p.end_date
-- GROUP BY 
--   p.product_id;


-- select u.product_id, (p.price*u.units)
-- from Prices p join UnitsSold u
-- on p.product_id=u.product_id
-- where u.purchase_date between p.start_date and p.end_date


-- select u.product_id, sum(p.price*u.units)/count( u.product_id )
-- from Prices p join UnitsSold u
-- on p.product_id=u.product_id
-- where u.purchase_date between p.start_date and p.end_date

--Wrong sol
-- select u.product_id, round(1.0* sum(p.price*u.units)/sum( u.units ),2) as average_price
-- from Prices p join UnitsSold u
-- on p.product_id=u.product_id

-- where u.purchase_date between p.start_date and p.end_date --and (select count(product_id) from UnitsSold ) !=0
-- group by u.product_id 
--Wrong sol
select  p.product_id ,
round(
    coalesce(1.0*sum(p.price* u.units) / nullif (sum(u.units),0),0),2)
as average_price

from Prices p left join UnitsSold u
on p.product_id=u.product_id
and  (u.purchase_date between p.start_date and p.end_date )
group by p.product_id 


-- WITH CTE as(
-- select p.product_id, round(1.0*sum(p.price*u.units) / sum(u.units),2) as average_price
-- from Prices p join UnitsSold u
-- on p.product_id=u.product_id
-- where u.purchase_date between p.start_date and p.end_date 
-- --group by p.product_id 
-- )

-- select * from CTE;
