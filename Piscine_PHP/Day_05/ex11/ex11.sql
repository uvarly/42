SELECT UPPER(last_name) AS NAME, first_name, price
FROM user_card
LEFT JOIN member ON user_card.id_user = member.id_member
LEFT JOIN subscription ON member.id_sub = subscription.id_sub
WHERE subscription.price > 42
ORDER BY first_name, last_name ASC;
