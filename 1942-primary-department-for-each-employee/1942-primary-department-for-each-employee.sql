/* Write your T-SQL query statement below */
-- select employee_id,department_id from Employee 
-- where primary_flag='Y' 

select e1.employee_id,e1.department_id from Employee e1
where e1.primary_flag='Y' OR
  e1.employee_id  in 
(select employee_id  from Employee 
where primary_flag='N' and employee_id  not in (select e3 .employee_id    from Employee e3
where e3.primary_flag='Y' 
group by e3.employee_id 
having count(*) =1 )  
group by employee_id 
having count(*) =1 )
;

-- select employee_id ,count(*)  from Employee 
-- where primary_flag='N' 
-- group by employee_id 
-- having count(*) =1 ;

-- select employee_id   from Employee 
-- where primary_flag='Y' 
-- group by employee_id 
-- having count(*) =1 ;
