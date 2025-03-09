# Write your MySQL query statement below
SELECT Name AS Customers
FROM Customers
WHERE referee_id != 2 OR referee_id IS NULL;
