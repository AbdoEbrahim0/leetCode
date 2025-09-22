/* Write your T-SQL query statement below */
-- select sum(case when num =1  then 1 else 0 end)
-- from Logs
-- ;

-- select distinct l1.num as ConsecutiveNums --ditinct to remove dublicated as i make
-- from Logs as l1
-- where l1.id = (select l1.id from Logs as l2 where (l1.num=l2.num) and  l2.id-l1.id=1  ) --there is no output when using select l2.id
-- and   l1.id  = (select l1.id from Logs as l3 where (l1.num=l3.num) and 2=l3.id-l1.id);  --there is no output when using select l3.id

select distinct l1.num as ConsecutiveNums
from Logs as l1 join Logs as l2 on   l2.id-l1.id= 1 and (l1.num=l2.num)
                join Logs as l3 on l3.id-l1.id =2 and (l1.num=l3.num);
 
