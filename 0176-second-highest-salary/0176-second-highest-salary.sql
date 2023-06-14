with cte as(
  select
    *
    , dense_rank() over(order by salary desc) as ranks
  from employee
)

select coalesce(
  (
    select salary
    from cte 
    where ranks=2
    limit 1
  ),
  NULL
) as SecondHighestSalary