/* Write your T-SQL query statement below */

-- [using join Only]

-- select  c.name as Customers --,o.id
-- from Orders as o right join Customers as c
-- on c.id=o.customerId
-- where o.id is NULL


--[group by name and join]

-- select c.name as Customers 
-- from Orders as o right join Customers as c
-- on c.id=o.customerId
-- group by c.id, c.name
-- having count(o.id) =0

--[not in] 

select name as Customers 
from Customers 
where id not in (select customerId from Orders) 
