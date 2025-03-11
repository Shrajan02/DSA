SELECT project_id, ROUND(AVG(experience_years), 2) AS average_years
FROM Project p
JOIN Employee em
WHERE p.employee_id = em.employee_id
GROUP BY project_id;
