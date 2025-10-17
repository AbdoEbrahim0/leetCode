/* Write your T-SQL query statement below */
-- select email as Email
-- from Person 
-- where email

-- select email as Email
-- from Person  
-- group by Email
-- having count(*)>1

select distinct p2.email as Email
from Person p1 join Person p2 --fk chiled  pk parent
on  p2.id !=p1.id  and p1.email=p2.email