WITH daily_revenue AS (
    SELECT 
        visited_on,
        SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
),
moving_avg AS (
    SELECT
        visited_on,
        SUM(amount) OVER (
            ORDER BY visited_on 
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ) AS amount,
        AVG(amount * 1.0) OVER (
            ORDER BY visited_on 
            ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
        ) AS average_amount
    FROM daily_revenue
)
SELECT
    visited_on,
    amount,
    ROUND(average_amount, 2) AS average_amount
FROM moving_avg
WHERE visited_on >= (
    SELECT DATEADD(DAY, 6, MIN(visited_on)) 
    FROM daily_revenue
)
ORDER BY visited_on;
