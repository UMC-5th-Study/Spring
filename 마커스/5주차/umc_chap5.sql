select * from mission where id in 
(select mission_id from user_mission where user_mission.id = mission.id 
and status = 'ongoing') 
order by mission.created_at desc limit 5;

select * from mission where id in 
(select mission_id from user_mission where user_mission.id = mission.id 
and status = 'cleared') 
order by mission.created_at desc limit 5;

INSERT INTO review (user_id, store_id, rate, body, created_at, updated_at) 
VALUES (1, 123, 5.0, '음 너무 맛있어요 포인트도 얻고...', NOW(), NOW());

SELECT * FROM mission WHERE status = '진행 가능' 
AND store_id IN (SELECT id FROM store WHERE city = 
(SELECT city FROM user WHERE id = 1))
ORDER BY created_at DESC LIMIT 5 OFFSET 0;

SELECT point, city FROM user;

SELECT name, email, point, phone FROM user WHERE id = 1;

SELECT r.*, s.name AS store_name 
FROM review r JOIN store s ON r.store_id = s.id
WHERE r.user_id = 1 
AND EXISTS (SELECT * FROM user u WHERE u.id = r.user_id)