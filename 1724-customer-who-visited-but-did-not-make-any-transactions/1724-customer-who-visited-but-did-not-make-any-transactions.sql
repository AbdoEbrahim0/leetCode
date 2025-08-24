/* Write your T-SQL query statement below */
select  customer_id ,count(Visits.visit_id) as count_no_trans  from Visits left outer join Transactions ON   Visits.visit_id =Transactions.visit_id where Transactions.transaction_id is null group by customer_id

/* select  customer_id ,count(visit_id) as count_no_trans from Visits where visit_id not in (select visit_id from Transactions) group by  customer_id */