# Write your MySQL query statement below
SELECT
    a.name,
    b.unique_id
FROM Employees AS a 
LEFT JOIN EmployeeUNI AS b
on a.id = b.id;    
    
