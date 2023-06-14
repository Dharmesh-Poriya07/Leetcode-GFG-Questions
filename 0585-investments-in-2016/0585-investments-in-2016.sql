
with cte1 as(
  select concat(lat,',',lon) as location
  from insurance
  group by lat,lon
  having count(pid)>1
),

cte2 as(
  select
    distinct i1.*
  from insurance i1
  join insurance i2
  on i1.tiv_2015=i2.tiv_2015
  where i1.pid<>i2.pid and concat(i1.lat,',',i1.lon) not in (
    select * from cte1
  )
)

select round(sum(tiv_2016),2) as tiv_2016 from cte2;