/* Write your T-SQL query statement below */
select id from Weather as w1 where  w1.temperature > (select w2.temperature from Weather as w2 where w1.recordDate =DATEADD(DAY, 1, w2.recordDate ) ) 

-- SELECT w1.id
-- FROM Weather w1
-- JOIN Weather w2
--   ON w1.recordDate = DATEADD(DAY, 1, w2.recordDate)
-- WHERE w1.temperature > w2.temperature;

--   (select w2.temperature from Weather ); 