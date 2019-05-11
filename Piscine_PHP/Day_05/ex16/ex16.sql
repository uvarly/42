SELECT COUNT(*) AS movies
FROM member_history
WHERE date BETWEEN '10-30-2006' AND '07-27-2007' OR (MONTH(date) = 12 AND DAY(date) = 24);
