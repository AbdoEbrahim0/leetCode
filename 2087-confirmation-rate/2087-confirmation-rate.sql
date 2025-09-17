/* Write your T-SQL query statement below */
-- select s.user_id,
--     case when c.user_id is null then  0 
--     else (
--     select count(*)
--     from Confirmations
--     where action ='confirmed'
--     group by Confirmations.user_id)
--     end
    
--  as confirmation_rate
-- from Signups as s left join Confirmations as c
-- on s.user_id=c.user_id
-- group by s.user_id;
-- you can escape divide by ZERO by divide by null
select s.user_id,
    round(
        1.0* sum(case when c.action ='confirmed'  then  1 else 0 end)  /
        case when count(c.action) =0 then 1 else count(c.action) end  
    ,2)
 as confirmation_rate
from Signups as s left join Confirmations as c
on s.user_id=c.user_id
group by s.user_id;
 

