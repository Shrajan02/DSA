SELECT eu.unique_id, em.name
FROM Employees em
LEFT JOIN EmployeeUNI eu
ON em.id = eu.id;
