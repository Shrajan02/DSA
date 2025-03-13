SELECT su.user_id, ROUND(IFNULL(AVG(action='confirmed'), 0), 2) AS confirmation_rate
FROM Signups su
LEFT JOIN Confirmations conf
ON su.user_id = conf.user_id 
GROUP BY su.user_id;

