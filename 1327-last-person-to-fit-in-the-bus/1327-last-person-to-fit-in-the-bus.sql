# using window function
-- CTE (Common Table Expression): a temp result set (virtual table) within a larger query
WITH cte AS (
    SELECT *, SUM(weight) OVER (ORDER BY turn) AS total_weight
    FROM Queue
)

SELECT person_name
FROM cte
WHERE total_weight <= 1000
ORDER BY turn DESC
LIMIT 1;