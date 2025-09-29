/* Write your T-SQL query statement below */
--wrong approach
-- select sum (i1.tiv_2016  ) as tiv_2016
-- from Insurance as i1 
-- join Insurance as i2
-- on i1.tiv_2015=i2.tiv_2015  and  i1.lat not in (select lat from Insurance where i1.pid!=pid)
-- and i1.lon not in (select lon from Insurance where i1.pid!=pid)

WITH InsuranceWithCounts AS (
    SELECT 
        tiv_2016,
        COUNT(*) OVER (PARTITION BY tiv_2015) AS tiv_2015_count,
        COUNT(*) OVER (PARTITION BY lat, lon) AS location_count
    FROM Insurance
)
SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM InsuranceWithCounts
WHERE tiv_2015_count > 1
  AND location_count = 1;


-- select i1.tiv_2015,sum (  i1.tiv_2016  )
-- from Insurance as i1
-- join Insurance as i2
-- on i1.lat !=i2.lat  and i1.lon!=i2.lon
-- group by i1.tiv_2015 

-- select tiv_2015,lat,lon ,sum (  tiv_2016  )
-- from Insurance 
-- group by tiv_2015,lat,lon
