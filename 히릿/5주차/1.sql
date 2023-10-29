select mission.point, store.name, mission.content, mission_progress.status
from mission_progress
         join mission on mission_progress.mission_id = mission.id
         join store on store.id = mission.store_id
         join user on mission_progress.user_id = user.id
where mission_progress.user_id = 1 order by mission_progress.created_at desc limit 15;