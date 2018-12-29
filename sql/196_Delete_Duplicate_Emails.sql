# Write your MySQL query statement below
delete a from Person a
inner join Person b
on a.Email=b.Email
where a.Id>b.Id
