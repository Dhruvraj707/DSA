# Write your MySQL query statement below
SELECT firstName, lastName  , city,state  FROM Person as p left join Address as a on p.personId  = a.personId    ; 