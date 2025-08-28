/* Write your T-SQL query statement below */
-- select p.product_id ,avg(p.price *u.units)as average_price from Prices as p join UnitsSold as u on 
-- u.product_id = p.product_id
-- where 
-- u.purchase_date < p.end_date and  u.purchase_date > start_date;
SELECT 
  p.product_id,
  ISNULL(ROUND(SUM(CAST(p.price * u.units AS FLOAT)) / NULLIF(SUM(u.units), 0), 2), 0) AS average_price
FROM 
  Prices p
LEFT JOIN 
  UnitsSold u 
  ON p.product_id = u.product_id 
     AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY 
  p.product_id;

