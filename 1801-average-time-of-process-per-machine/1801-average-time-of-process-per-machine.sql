/* Write your T-SQL query statement below */

-- select  machine_id ,sum(timestamp) as sumOfEnd  from Activity where activity_type ='end' group by  machine_id  ;

-- select  machine_id ,sum(timestamp) as sumOfstart  from Activity where activity_type ='start' group by  machine_id  ;


-- select distinct   machine_id , (sumOfEnd - sumOfstart ) /2 as   processing_time from Activity

SELECT 
    a.machine_id,
    ROUND(AVG(b.timestamp - a.timestamp), 3) AS processing_time
FROM 
    Activity a
JOIN 
    Activity b
    ON a.machine_id = b.machine_id 
    AND a.process_id = b.process_id
WHERE 
    a.activity_type = 'start' 
    AND b.activity_type = 'end'
GROUP BY 
    a.machine_id;


-- 1.788
-- 0.98 +0.808 =1.788 /2 =0.894
-- 2.97-0.98 =1.99/2 =0.995