
with cte as (
    select product_id, max(change_date) as change_date
    from products
    where change_date <= '2019-08-16'
    group by product_id
)

select product_id,new_price as price
from products
where (product_id,change_date) in (
    select product_id, change_date
    from cte
)

union

select product_id, 10 as price
from Products
where product_id not in (
    select product_id from cte
)
