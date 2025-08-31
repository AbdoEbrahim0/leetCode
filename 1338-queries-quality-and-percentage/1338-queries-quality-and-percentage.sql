/* Write your T-SQL query statement below */
-- wrong code 1
-- select query_name ,
-- cast( sum(rating*1.0 /position) / count(*)  as decimal (10,2)) as quality,
-- cast(sum(rating<3)*100.0/  count(*) as decimal(10,2)) as poor_query_percentage
-- from Queries
-- group by query_name;

-- wrong code 2
-- SELECT 
--   query_name,
--   CAST(SUM(rating * 1.0 / position) / COUNT(*) AS DECIMAL(10, 2)) AS quality,
--   CAST(SUM(rating < 3) * 100.0 / COUNT(*) AS DECIMAL(10, 2)) AS poor_query_percentage
-- FROM Queries
-- GROUP BY query_name;
-- corrected code
SELECT 
  query_name,
  CAST(SUM(1.0 * rating / position) / COUNT(query_name) AS DECIMAL(10, 2)) AS quality,
  CAST(SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) * 100.0 / COUNT(query_name) AS DECIMAL(10, 2)) AS poor_query_percentage
FROM Queries
GROUP BY query_name;
