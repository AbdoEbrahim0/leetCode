/* Write your T-SQL query statement below */
select  c.name as Customers --,o.id
from Orders as o right join Customers as c
on c.id=o.customerId
where o.id is NULL
