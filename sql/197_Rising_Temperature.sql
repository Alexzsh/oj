# Write your MySQL query statement below
select w2.id from Weather as w1
inner join Weather as w2
on TO_DAYS(w2.RecordDate)=TO_DAYS(w1.RecordDate)+1
where w2.Temperature>w1.Temperature
