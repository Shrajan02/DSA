# Subquery HAVING approach
SELECT name FROM Employee
WHERE id IN (
    SELECT managerId FROM Employee
    GROUP BY managerId
    HAVING COUNT(DISTINCT id) >= 5
);
