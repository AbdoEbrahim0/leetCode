/* Write your T-SQL query statement below */
-- select unique_id ,name from EmployeeUNI right join Employees on EmployeeUNI.id = Employees.id;


select  uni.unique_id , e.name
from Employees e left join EmployeeUNI uni
on e.id=uni.id
