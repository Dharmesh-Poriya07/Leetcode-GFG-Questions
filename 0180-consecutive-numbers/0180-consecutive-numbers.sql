# Approach: 01
select distinct num as ConsecutiveNums
from logs
where 
  (id+1,num) in (select * from logs) 
  and 
  (id+2,num) in (select * from logs);

# Approach: 02