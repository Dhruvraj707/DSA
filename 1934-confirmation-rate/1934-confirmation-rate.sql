# Write your MySQL query statement below
SELECT s.user_id,     ROUND(
        IFNULL(SUM(c.action = 'confirmed') / COUNT(c.action), 0),
        2
    ) AS confirmation_rate
FROM Signups AS s
LEFT JOIN  Confirmations as c
ON s.user_id = c.user_id 
Group by s.user_id ;

