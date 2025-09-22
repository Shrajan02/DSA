# HAVING should always be used with GROUP BY since its an aggregating clause, so don't use DISTINCT
SELECT customer_id
FROM Customer
GROUP BY customer_id
HAVING 
    COUNT(DISTINCT product_key) 
    = 
    (SELECT COUNT(product_key) FROM Product);



