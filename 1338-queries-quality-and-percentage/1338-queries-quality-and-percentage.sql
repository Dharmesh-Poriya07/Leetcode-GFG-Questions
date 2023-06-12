
select 
query_name, 
round(sum(rating/position)/count(*),2) as quality, 
round((sum(rating<3)/count(*))*100,2) as poor_query_percentage
from queries
group by query_name;