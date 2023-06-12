select max(num) as num
from mynumbers
where num in (select  max(num) as num
from mynumbers
group by num having count(num)=1);