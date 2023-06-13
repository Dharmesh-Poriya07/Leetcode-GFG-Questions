# Approach: 01
/*
select distinct num as ConsecutiveNums
from logs
where 
  (id+1,num) in (select * from logs) 
  and 
  (id+2,num) in (select * from logs);
*/

# Approach: 02 
with cte as (
  select num, lead(num,1) over(order by id) as lead1, lead(num,2) over(order by id) as lead2
  from logs
)

select distinct num as ConsecutiveNums from cte where num=lead1 and num=lead2;