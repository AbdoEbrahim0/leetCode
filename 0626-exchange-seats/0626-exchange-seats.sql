/* Write your T-SQL query statement below */

--[subQuerey without order by]

-- select s1.id, (case  
--     when s1.id%2=0  
--     then    (select student from Seat as s3 where s3.id=s1.id-1)
--     when s1.id%2=1 and s1.id+1 <= (select max(id) from Seat)
--     then    (select student from Seat as s2 where s2.id=s1.id+1)
--     else    s1.student
-- end)
-- as student
-- from Seat as s1
 

 select 
    case 
    when s1.id %2=1 and s1.id+1 <=(select max(s2.id) from Seat as s2)
    then s1.id+1

    when s1.id %2=0 
    then s1.id-1
    else s1.id
    end as id
, s1.student 
from Seat as s1
order by id asc; -- i dont know why when ordering by s1.id not arrange them