/* Write your T-SQL query statement below */

--[dense rank window fn  ]
--  select score, dense_rank() over (order by score Desc) as rank
-- from Scores

--[from GPT i asked for alternative but nice to know]
/*
--How many  scores >= current score
SELECT 
    s1.score,
    (SELECT COUNT( s2.score) 
     FROM Scores s2 
     WHERE s2.score >= s1.score) AS rank
FROM Scores s1
ORDER BY s1.score DESC;
| score | rank |
| ----- | ---- |
| 4     | 2    |
| 4     | 2    |
| 3.85  | 3    |
| 3.65  | 5    |
| 3.65  | 5    |
| 3.5   | 6    |
*/
--How many distinctive scores >= current score
SELECT 
    s1.score,
    (SELECT COUNT(distinct  s2.score) 
     FROM Scores s2 
     WHERE s2.score >= s1.score) AS rank
FROM Scores s1
ORDER BY s1.score DESC;

/*
| score | rank |
| ----- | ---- |
| 4     | 1    |
| 4     | 1    |
| 3.85  | 2    |
| 3.65  | 3    |
| 3.65  | 3    |
| 3.5   | 4    |
*/