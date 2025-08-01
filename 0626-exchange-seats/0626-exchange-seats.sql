SELECT 
    CASE
        WHEN id % 2 = 0 THEN id - 1  -- decrement
        WHEN id % 2 = 1 AND id + 1 IN (SELECT id FROM Seat) THEN id + 1  -- check next seat exists, then increment
        ELSE id  -- for last seat, same id
    END AS id,
    student
FROM Seat
ORDER BY id;

