# Write your MySQL query statement below
select q.query_name, ROUND(AVG(q.rating/q.position),2) as quality, ROUND((select COUNT(rating) 
from Queries where rating<3 AND query_name=q.query_name)/(COUNT(q.rating))*100,2) 
as poor_query_percentage from Queries q
group by query_name