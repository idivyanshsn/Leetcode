# Write your MySQL query statement below
select today.id 
from weather today 
join weather yesterday on 
datediff(today.recorddate,yesterday.recorddate)=1 
where today.temperature>yesterday.temperature;