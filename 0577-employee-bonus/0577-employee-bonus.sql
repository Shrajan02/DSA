SELECT em.name, bn.bonus
FROM Employee em
LEFT JOIN Bonus bn
ON em.empId = bn.empId
WHERE bonus < 1000 OR bonus IS NULL; 