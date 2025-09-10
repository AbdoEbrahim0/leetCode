/* Write your T-SQL query statement below */
-- update Users set [name] = UPPER([name]);

-- select * from Users 
-- order by user_id; 

-- UPDATE Users 
-- SET [name] = UPPER([name]);

-- SELECT * 
-- FROM Users
-- ORDER BY user_id;
-- SELECT user_id ,UPPER(name) AS name
-- FROM Users
-- ORDER BY user_id
-- ;

SELECT user_id,  upper (left ( lower_name,1)) + substring(lower_name,2,len (lower_name)) as name
FROM (
    SELECT user_id, LOWER([name]) AS lower_name
    FROM Users
) AS sub

ORDER BY user_id
;