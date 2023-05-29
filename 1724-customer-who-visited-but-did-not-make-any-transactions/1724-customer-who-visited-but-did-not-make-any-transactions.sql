# Write your MySQL query statement below

# using left join
# select v.customer_id, count(v.visit_id) as count_no_trans
# from visits v 
# left join transactions t
# on v.visit_id = t.visit_id
# where t.transaction_id is null
# group by v.customer_id;

# using sub query
select v.customer_id, count(v.visit_id) as count_no_trans
from visits v where v.visit_id 
not in (select t.visit_id from transactions t) 
group by v.customer_id;