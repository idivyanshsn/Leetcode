# Write your MySQL query statement below
SELECT 
DATE_FORMAT(trans_date,'%Y-%m') AS month,
country,
COUNT(*) AS trans_count,
SUM(CASE WHEN state='approved' THEN 1 ELSE 0 END) AS approved_count,
SUM(amount) as trans_total_amount,
sum(case when state='approved' then amount else 0 end) as approved_total_amount
from transactions
GROUP BY DATE_FORMAT(trans_date,'%Y-%m'),country