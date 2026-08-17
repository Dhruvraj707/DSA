# Write your MySQL query statement below
SELECT v.customer_id, count(v.visit_id) as count_no_trans
FROM Visits v
LEFT join Transactions t
on v.visit_id = t.visit_id
where t.transaction_id IS null
GROUP BY v.customer_id;