/* Write your T-SQL query statement below */
-- select email as Email
-- from Person 
-- where email

-- select email as Email
-- from Person  
-- group by Email
-- having count(*)>1

-- select distinct p1.email as Email
-- from Person p1 join Person p2 --fk chiled  pk parent
-- on  p2.id !=p1.id  and p1.email=p2.email

-- SELECT email AS Email
-- FROM Person
-- EXCEPT
-- SELECT email AS Email
-- FROM Person
-- GROUP BY email
-- HAVING COUNT(*) = 1;

-- SELECT DISTINCT email AS Email
-- FROM Person
-- WHERE email IN (
--     SELECT email
--     FROM Person
--     GROUP BY email
--     HAVING COUNT(*) > 1
-- );

with cte as (
select email, row_number()   over(partition by email order by email ) as rn
 from Person

)
select distinct email as Email
from CTE
where rn>1