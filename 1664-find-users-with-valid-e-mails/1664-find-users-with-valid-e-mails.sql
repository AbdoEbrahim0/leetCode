/* Write your T-SQL query statement below*/

-- select user_id ,name,mail
-- from Users
-- where mail  like '[A-Za-z]%@leetcode.com' 
--  and LEFT(mail, LEN(mail) - LEN('@leetcode.com')) not like '%[A-Za-z0-9._-]%';

-- SELECT user_id, name, mail
-- FROM Users
-- WHERE mail LIKE '[A-Za-z]%@leetcode.com'
--   AND LEFT(mail, LEN(mail) - LEN('@leetcode.com')) NOT LIKE '%[^A-Za-z0-9._-]%';


-- SELECT user_id, name, mail
-- FROM Users
-- WHERE mail LIKE '[A-Za-z][A-Za-z0-9._-]*@leetcode.com'
--   AND CHARINDEX('@', mail) = LEN(mail) - LEN('leetcode.com');

-- SELECT user_id, email
-- FROM Users
-- WHERE 
--     -- must contain exactly one '@'
--     LEN(email) - LEN(REPLACE(email, '@', '')) = 1
--     -- must contain exactly one '.'
--     AND LEN(email) - LEN(REPLACE(email, '.', '')) = 1
--     -- characters before @ must be alphanumeric
--     AND LEFT(email, CHARINDEX('@', email) - 1) NOT LIKE '%[^0-9a-zA-Z]%'
--     -- domain part before the dot must be alphanumeric
--     AND SUBSTRING(
--             email,
--             CHARINDEX('@', email) + 1,
--             CHARINDEX('.', email) - CHARINDEX('@', email) - 1
--         ) NOT LIKE '%[^0-9a-zA-Z]%'
--     -- domain part after the dot must be alphanumeric
--     AND RIGHT(email, LEN(email) - CHARINDEX('.', email)) NOT LIKE '%[^0-9a-zA-Z]%'
-- ORDER BY user_id;
-- SELECT user_id, name, mail
-- FROM Users
-- WHERE mail LIKE '[a-zA-Z]%@leetcode.com'
--   AND mail NOT LIKE '%[^a-zA-Z0-9._-]%@leetcode.com'
--   AND LEN(mail) - LEN(REPLACE(mail, '@', '')) = 1  -- Ensure only one @ symbol
--   AND CHARINDEX('@leetcode.com', mail) = LEN(mail) - LEN('@leetcode.com') + 1
--   and mail like '%@leetcode.com'
--   ; -- @ is at the right position

SELECT user_id, name, mail
FROM Users
WHERE RIGHT(mail, 13) COLLATE SQL_Latin1_General_CP1_CS_AS = '@leetcode.com'
  AND LEFT(mail, LEN(mail) - 13) LIKE '[a-zA-Z]%'
  AND LEFT(mail, LEN(mail) - 13) NOT LIKE '%[^a-zA-Z0-9._-]%';