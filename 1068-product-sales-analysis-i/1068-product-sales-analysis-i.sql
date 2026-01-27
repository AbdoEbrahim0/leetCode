/* Write your T-SQL query statement below */
-- select product_name, year, price from  Sales join Product on  Sales.product_id =Product.product_id;

--.Net

select p.product_name ,s.year,s.price
from Product  p join Sales s
on s.product_id=p.product_id