SELECT id 
FROM weather AS w1  
WHERE w1.temperature > (
    SELECT MAX(temperature)  
    FROM weather AS w2 
    WHERE w2.recordDate = w1.recordDate - INTERVAL 1 DAY
);
