/* Write your T-SQL query statement below */

-- select 'Low Salary' as category ,sum(case when income<20000  then 1 else 0 end) as accounts_count
-- from Accounts
-- union all 
-- select 'Average Salary' ,sum(case when income between 20000 and 50000 then 1 else 0 end) as accounts_count
-- from Accounts
-- union all
-- select 'High Salary' ,sum(case when income>50000  then 1 else 0 end) as accounts_count
-- from Accounts; 

SELECT 'Low Salary' AS category, COUNT(*) AS accounts_count
FROM Accounts
WHERE income < 20000

UNION ALL

SELECT 'Average Salary', COUNT(*)
FROM Accounts
WHERE income BETWEEN 20000 AND 50000

UNION ALL

SELECT 'High Salary', COUNT(*)
FROM Accounts
WHERE income > 50000;

