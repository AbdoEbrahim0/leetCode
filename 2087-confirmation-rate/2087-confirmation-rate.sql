/* Write your T-SQL query statement below */

-- you can escape divide by ZERO by divide by null
-- select s.user_id,
--     round(
--         1.0* sum(case when c.action ='confirmed'  then  1 else 0 end)  /
--         case when count(c.action) =0 then 1 else count(c.action) end  
--     ,2)
--  as confirmation_rate
-- from Signups as s left join Confirmations as c
-- on s.user_id=c.user_id
-- group by s.user_id;
 

select user_id, (select case when   round 
                    (1.0* sum (case when c.action ='confirmed'  then  1 else 0 end)
                    / sum (case when c.action  in ('confirmed', 'timeout')   then  1 else 0 end)
                    ,2) is null then 0 else 
                    round 
                    (1.0* sum (case when c.action ='confirmed'  then  1 else 0 end)
                    / sum (case when c.action  in ('confirmed', 'timeout')   then  1 else 0 end)
                    ,2) end
                    from Confirmations as c
                    where c.user_id=s.user_id
                     
                )
as confirmation_rate
from Signups as s;
