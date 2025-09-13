/* Write your T-SQL query statement below */
-- select *
-- from Patients 
-- where conditions like 'DIAB1%' or conditions like '% DIAB1%';

SELECT * 
FROM Patients 
WHERE PATINDEX('DIAB1%', conditions) > 0
 or  PATINDEX('% DIAB1%', conditions) > 0
