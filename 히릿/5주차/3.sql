select store.name, store_type.name, mission.content, mission.point, mission.deadline
from store
         join store_type on store.store_type_id = store_type.id
         join mission on store.id = mission.store_id
where store.address like '%상록구%' order by mission.deadline asc limit 15;