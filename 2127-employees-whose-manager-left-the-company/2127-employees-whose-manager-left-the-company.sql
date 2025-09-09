/* Write your T-SQL query statement below */
--  and (select 1 from Employees as e2 where e1.employee_id   );

-- select e1.employee_id from Employees e1 
-- where   e1.salary <30000 and  e1.manager_id not  in 
--  (select e2.employee_id from Employees as e2)
--  order by e1.employee_id asc;

-- select e1.employee_id  from Employees e1 
-- left join Employees as e2
-- on 
--   e1.manager_id =e2.employee_id
-- where   e1.salary <30000 and
-- e1.manager_id is not null
-- and e2.employee_id is null

-- order by e1.employee_id;
 
 SELECT e1.employee_id
FROM Employees e1
WHERE e1.salary < 30000
  AND e1.manager_id IS NOT NULL
  AND NOT EXISTS (
    SELECT 1
    FROM Employees e2
    WHERE e2.employee_id = e1.manager_id
  )
ORDER BY e1.employee_id ASC;
