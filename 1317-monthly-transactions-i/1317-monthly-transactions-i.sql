/* Write your T-SQL query statement below */
-- select year(trans_date)+'-'+month(trans_date)
-- from Transactions
--group by trans_date;

select LEFT(CONVERT(VARCHAR, trans_date, 23), 7)  as month ,country,count(trans_date) as trans_count ,
sum(case when state='approved' then 1 else 0 end) as approved_count, sum(amount) as trans_total_amount,
sum(case when state='approved' then amount else 0 end)  as  approved_total_amount
from Transactions
--where state='approved'
group by LEFT(CONVERT(VARCHAR, trans_date, 23), 7),country;