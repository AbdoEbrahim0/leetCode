/* Write your T-SQL query statement below */
-- select  r.contest_id ,
-- -- wrong
-- --  CAST ((count (r.user_id)*100.0
-- --  / count (u.user_id)) as decimal (10,2))   as percentage
-- CAST(COUNT(DISTINCT r.user_id) * 100.0 / COUNT(DISTINCT u.user_id) AS DECIMAL(10,2)) AS percentage
-- from  Users as u  join Register as r on 
-- r.user_id =u.user_id 
-- group by r.contest_id 
-- order by percentage desc , r.contest_id asc;

-- wrong approach using join 
-- But here's the catch:

-- ⚠️ Problem with COUNT(u.user_id) in a JOIN
-- When you JOIN, you're only counting users who actually registered for contests.

-- That means you're excluding users who never registered — which violates the problem requirement:

-- ✅ Why Subquery is better here
-- Using a subquery like this:
SELECT 
  r.contest_id,
  CAST(
    COUNT(DISTINCT r.user_id) * 100.0 / 
    (SELECT COUNT(*) FROM Users)
    AS DECIMAL(10,2)
  ) AS percentage
FROM Register r
GROUP BY r.contest_id
ORDER BY percentage DESC, r.contest_id ASC;

