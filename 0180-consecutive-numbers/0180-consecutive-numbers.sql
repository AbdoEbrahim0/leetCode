/* Write your T-SQL query statement below */
-- [using subquery ]

-- select distinct l1.num as ConsecutiveNums --ditinct to remove dublicated as i make
-- from Logs as l1
-- where l1.id = (select l1.id from Logs as l2 where (l1.num=l2.num) and  l2.id-l1.id=1  ) --there is no output when using select l2.id
-- and   l1.id  = (select l1.id from Logs as l3 where (l1.num=l3.num) and 2=l3.id-l1.id);  --there is no output when using select l3.id

--[using join]

-- select distinct l1.num as ConsecutiveNums
-- from Logs as l1 join Logs as l2 on   l2.id-l1.id= 1 and (l1.num=l2.num)
--                 join Logs as l3 on l3.id-l1.id =2 and (l1.num=l3.num);
 
 -- [case when ] 
SELECT DISTINCT num AS ConsecutiveNums
FROM (
  SELECT 
    num,
    CASE 
      WHEN num = LEAD(num, 1) OVER (ORDER BY id)
       AND num = LEAD(num, 2) OVER (ORDER BY id)
      THEN 1 ELSE 0
    END AS is_consecutive
  FROM Logs
) AS sub
WHERE is_consecutive = 1;


 --[using LeadFn to check consecutively]

-- SELECT DISTINCT num AS ConsecutiveNums
-- FROM (
--   SELECT 
--     num,
--     LEAD(num, 1) OVER (ORDER BY id) AS next1,
--     LEAD(num, 2) OVER (ORDER BY id) AS next2
--   FROM Logs
-- ) AS sub
-- WHERE num = next1 AND num = next2;

--showing output of subquery
-- | num | next1 | next2 |
-- | --- | ----- | ----- |
-- | 1   | 1     | 1     |
-- | 1   | 1     | 2     |
-- | 1   | 2     | 1     |
-- | 2   | 1     | 2     |
-- | 1   | 2     | 2     |
-- | 2   | 2     | null  |
-- | 2   | null  | null  |