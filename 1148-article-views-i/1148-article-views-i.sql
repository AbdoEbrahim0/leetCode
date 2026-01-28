/* Write your T-SQL query statement below */
-- select DISTINCT author_id as id from Views where author_id = viewer_id order by author_id;

--.net 

select  distinct author_id as id 
from Views
where viewer_id=author_id;