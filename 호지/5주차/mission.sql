select
    m.idx as missionIdx,
    m.title as missionTitle,
    m.content as missionContent,
    m.point as missionPoint,
    m.status as missionStatus,
    mr.idx as missionReviewIdx,
    m.createdDate as missionCreatedDate,
    m.modifiedDate as missionModifiedDate
from mission m
left join food_store as fs on m.foodStoreIdx = fs.idx
left join mission_review as mr on m.idx = mr.missionIdx
where
    m.userIdx = 31
    and m.status = 'SUCCESS'
    and (point < 8721
    or (point = 8721 and m.createdDate < '2023-10-29 11:34:38.508994'))
order by point DESC, m.createdDate DESC
limit 5;


insert into mission_review
    (content, score, userIdx, foodStoreIdx, missionIdx)
values ('맛있다!', 4.5, 31, 23, 8158);

select
    count(*)
from mission
where
    userIdx = 31;

explain select
    m.idx as missionIdx,
    m.title as missionTitle,
    m.content as missionContent,
    m.point as missionPoint,
    m.status as missionStatus,
    m.targetDate as missionTargetDate,
    m.targetPrice as missionTargetPrice,
    fs.idx as foodStoreIdx,
    fs.name as foodStoreName,
    ft.name as foodTypeName
from mission m
left join food_store as fs on m.foodStoreIdx = fs.idx
left join food_store_type as fst on fs.idx = fst.foodStoreIdx
left join food_type as ft on fst.foodTypeIdx = ft.idx
left join region as r on m.regionIdx = r.idx
where
    m.userIdx = 31
    and m.status not in ('SUCCESS')
    and r.name = '인계동'
    and m.idx > 5756
order by missionIdx ASC
limit 5;

explain select * from mission
union
select * from user;