/* Write your T-SQL query statement below */
-- select email as Email
-- from Person 
-- where email

select email as Email
from Person  
group by email
having count(*)>1