SELECT product_id FROM Products 
WHERE low_fats = 'Y' 
INTERSECT
SELECT product_id FROM Products 
WHERE recyclable = 'Y';