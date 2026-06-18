# Write your MySQL query statement below
select firstName, lastName, city, state from Address a right JOIN person d ON a.personId = d.personId