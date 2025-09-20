/* Write your T-SQL query statement below */
-- select count(*)
-- from Accounts
-- where income <20000;

-- select count(*)
-- from Accounts
-- where income between 20000 and 50000;

-- select count(*)
-- from Accounts
-- where income >50000;


-- insert into temp (category,accounts_count)
-- select 'Low Salary', count(*) from Accounts where income <20000;

-- insert into temp (category,accounts_count)
-- select 'Low Salary' ,count(*) from Accounts where income <20000 

-- select account_id as accounts_count
-- from Accounts
-- group by account_id;

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

