/* Write your T-SQL query statement below */
-- select id from Weather as w1 where  w1.temperature > (select w2.temperature from Weather as w2 where w1.recordDate =DATEADD(DAY, 1, w2.recordDate ) ) 

-- SELECT w1.id
-- FROM Weather w1
-- JOIN Weather w2
--   ON w1.recordDate = DATEADD(DAY, 1, w2.recordDate)
-- WHERE w1.temperature > w2.temperature;

--.Net
select w1.id as Id
from Weather w1 join Weather w2
on w1.id != w2.id and  DATEDIFF(DAY,  w2.recordDate,w1.recordDate) = 1 where w1.temperature>w2.temperature

-- select w2.id as Id
-- from Weather w1 join Weather w2
-- on  w2.recordDate = DATEADD(DAY, 1, w1.recordDate)
-- where w2.temperature>w1.temperature
