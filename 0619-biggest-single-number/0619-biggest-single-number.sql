# Write your MySQL query statement below
-- SELECT MAX(num) AS num
-- FROM MyNumbers
-- WHERE num NOT IN (
--     SELECT num
--     FROM MyNumbers
--     GROUP BY num
--     HAVING COUNT(*) > 1
-- );

SELECT MAX(num) AS num
FROM MyNumbers
WHERE num IN (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(num) = 1
);
