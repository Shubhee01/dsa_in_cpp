# Write your MySQL query statement below
select p1.product_id, ROUND(SUM(p1.price*s1.units)/SUM(s1.units),2) as average_price from Prices p1 JOIN UnitsSold s1 
ON p1.product_id=s1.product_id where s1.purchase_date<=p1.end_date AND s1.purchase_date>=p1.start_date 
group by p1.product_id
