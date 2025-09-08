/* Write your T-SQL query statement below */
select x,y,z,
    CASE
    when  (x+y)> z and (x+z)>y and (y+z) >x  then 'Yes' else 'No' 
    END 
as triangle 
from Triangle ;
 