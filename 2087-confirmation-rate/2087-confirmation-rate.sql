select s.user_id,
case
  when c.user_id is null then 0.00
  else round(sum(c.action='confirmed')/count(c.user_id),2)
end
as confirmation_rate
from signups s 
left join confirmations c 
on s.user_id = c.user_id
group by s.user_id 
order by s.user_id;