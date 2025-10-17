/* Write your T-SQL query statement below */

--[group by ]

-- select email as Email
-- from Person  
-- group by Email
-- having count(*)>1

--[self join]

-- select distinct p1.email as Email
-- from Person p1 join Person p2 --fk chiled  pk parent
-- on  p2.id !=p1.id  and p1.email=p2.email

--[Except with group by ]

-- SELECT email AS Email
-- FROM Person
-- EXCEPT
-- SELECT email AS Email
-- FROM Person
-- GROUP BY email
-- HAVING COUNT(*) = 1;

--[subQuery with group by ]

-- SELECT DISTINCT email AS Email
-- FROM Person
-- WHERE email IN (
--     SELECT email
--     FROM Person
--     GROUP BY email
--     HAVING COUNT(*) > 1
-- );

--[CTE with Window fn]

-- with cte as (
-- select email, row_number()   over(partition by email order by id ) as rn
--  from Person
-- )
-- select distinct email as Email
-- from CTE
-- where rn>1

--[SubQuery with Window fn]
SELECT DISTINCT email AS Email
FROM (
    SELECT email, ROW_NUMBER() OVER (PARTITION BY email ORDER BY id) AS rn
    FROM Person
) AS ranked
WHERE rn > 1;
