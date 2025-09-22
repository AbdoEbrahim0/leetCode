/* Write your T-SQL query statement below */
-- select sum(case when num =1  then 1 else 0 end)
-- from Logs
-- ;

-- select l1.num
-- from Logs as l1
-- where l1.id =(select l2.id from Logs as l2 where (l1.num=l2.num) and 1=l2.id-l1.id )
-- and   l1.id =(select l3.id from Logs as l3 where (l1.num=l3.num) and 2=l3.id-l1.id )

select distinct l1.num as ConsecutiveNums
from Logs as l1
where l1.id = (select l1.id from Logs as l2 where (l1.num=l2.num) and  l2.id-l1.id=1  ) --there is no output when using select l2.id
and   l1.id  = (select l1.id from Logs as l3 where (l1.num=l3.num) and 2=l3.id-l1.id);--there is no output when using select l3.id



-- select l2.id from Logs as l2 where 1=l2.id-1 ;

-- (select l3.id from Logs as l3 where 1=l3.id-2 )

