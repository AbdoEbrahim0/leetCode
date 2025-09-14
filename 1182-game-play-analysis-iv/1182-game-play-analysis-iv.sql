/* Write your T-SQL query statement below */
-- select  count(distinct player_id)
-- from Activity; 
-- out:3

-- select count(a1.player_id)
-- from Activity as a1
-- join Activity as a2
-- on datediff(day,a1.event_date,a2.event_date) =1 and a1.player_id =a2.player_id ;
-- out : 1

-- fail in test case 
-- select cast (  1.0*(select count( a1.player_id) from Activity as a1 join Activity as a2
-- on datediff(day,a1.event_date,a2.event_date) =1 and 
-- a1.player_id =a2.player_id ) /(
-- select count(distinct a3.player_id) from Activity as a3
--     ) as decimal(10,2) ) as fraction; 

-- corrected version:
-- select cast ( 
--     1.0* count(distinct a1.player_id) 
-- / (select count(distinct a3.player_id) from Activity as a3)
-- as decimal(10,2) ) as fraction
--  from Activity as a1 join Activity as a2
-- on a1.player_id =a2.player_id  
-- and  datediff(day,a1.event_date,a2.event_date) =1   ; 


-- SELECT 
--   CAST(
--     1.0 * COUNT(DISTINCT a1.player_id) 
--     / (SELECT COUNT(DISTINCT player_id) FROM Activity)
--     AS DECIMAL(10,2)
--   ) AS fraction
-- FROM Activity a1
-- JOIN Activity a2 
--   ON a1.player_id = a2.player_id 
--  AND DATEDIFF(day, a1.event_date, a2.event_date) = 1;

SELECT 
  ROUND(
    1.0 * SUM(CASE WHEN a.event_date = DATEADD(day, 1, f.first_day) THEN 1 ELSE 0 END)
    / COUNT(DISTINCT f.player_id),
    2
  ) AS fraction
FROM (
    SELECT player_id, MIN(event_date) AS first_day
    FROM Activity
    GROUP BY player_id
) f
LEFT JOIN Activity a
  ON f.player_id = a.player_id;
