-- when change date is beyond 16th
SELECT DISTINCT product_id, 10 AS price 
FROM Products 
WHERE product_id NOT IN (
    SELECT DISTINCT product_id 
    FROM Products 
    WHERE change_date <= '2019-08-16'
)
UNION 
-- when change date is less than equal to 16th
SELECT product_id, new_price AS price 
FROM Products 
WHERE (product_id, change_date) IN (
    SELECT product_id, MAX(change_date) AS date 
    FROM Products 
    WHERE change_date <= '2019-08-16' 
    GROUP BY product_id
);