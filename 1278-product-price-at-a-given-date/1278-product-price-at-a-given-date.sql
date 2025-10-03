/* Write your T-SQL query statement below */
-- with cte as (
-- select product_id , new_price , change_date  dense_rank() over (change_date desc) as drnk
-- from Products
-- where change_date <= '2019-8-16'

-- ) as Ranked
-- select * from cte

WITH RankedPrices AS (
    SELECT 
        product_id,
        new_price,
        ROW_NUMBER() OVER (
            PARTITION BY product_id 
            ORDER BY change_date DESC
        ) AS rn
    FROM Products
    WHERE change_date <= '2019-08-16'
)
SELECT 
    p.product_id,
    ISNULL(r.new_price, 10) AS price
FROM (
    SELECT DISTINCT product_id FROM Products
) p
LEFT JOIN RankedPrices r
    ON p.product_id = r.product_id AND r.rn = 1;
