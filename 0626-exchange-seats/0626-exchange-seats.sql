/* Write your T-SQL query statement below */

select s1.id, (case  
    when s1.id%2=0  
    then    (select student from Seat as s3 where s3.id=s1.id-1)
    when s1.id%2=1 and s1.id+1 <= (select max(id) from Seat)
    then    (select student from Seat as s2 where s2.id=s1.id+1)
    else    s1.student
end)
as student
from Seat as s1
 

-- select *
-- from temp;

-- delete from cte 
-- where id=(select top 1 id from cte order by id desc)

-- select *
-- from cte;
