/* Write your T-SQL query statement below */
-- select user_id,count(*)  as cnt 
-- from MovieRating
-- group by user_id
-- order by cnt desc
-- with cte as (
-- select user_id,count(*)  as cnt 
-- from MovieRating
-- group by user_id
-- -- order by cnt desc
-- ), cte2 as (
-- select movie_id ,round(avg(1.0*rating),2) as avg 
-- from MovieRating
-- where month(created_at)=2
-- group by movie_id
-- )  
-- select top 1 u.name as results
-- from Users as u
-- join cte
-- on cte.user_id =u.user_id
-- order by u.name  asc , cte.cnt desc

-- union all 


-- select top 1 m.title as results
-- from Movies as m
-- join cte2
-- on cte2.movie_id =m.movie_id
-- order by  cte2.avg desc ,m.title  asc ;



WITH cte AS (
    SELECT user_id, COUNT(*) AS cnt
    FROM MovieRating
    GROUP BY user_id
),
cte2 AS (
    SELECT movie_id, ROUND(AVG(1.0 * rating), 2) AS avg
    FROM MovieRating
    WHERE MONTH(created_at) = 2 AND YEAR(created_at) = 2020
    GROUP BY movie_id
)
SELECT results
FROM (
    SELECT TOP 1 u.name AS results
    FROM Users AS u
    JOIN cte ON cte.user_id = u.user_id
    ORDER BY cte.cnt DESC, u.name ASC
) AS t1

UNION ALL

SELECT results
FROM (
    SELECT TOP 1 m.title AS results
    FROM Movies AS m
    JOIN cte2 ON cte2.movie_id = m.movie_id
    ORDER BY cte2.avg DESC, m.title ASC
) AS t2;
