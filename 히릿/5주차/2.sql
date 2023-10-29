select user.nickname, review.score, review.content, review_reply.content
from review
         join user on review.user_id = user.id
         left join review_reply on review.id = review_reply.review_id
where review.store_id = 1 order by review.created_at desc;