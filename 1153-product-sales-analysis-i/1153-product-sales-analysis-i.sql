/* Write your T-SQL query statement below */
select product_name, year, price from  Sales join Product on  Sales.product_id =Product.product_id;