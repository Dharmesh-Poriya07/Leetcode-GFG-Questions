# solution-1
/*
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
*/

# solution-2
/*
with cte as(
  select distinct salary from employee order by salary desc limit 2
)

select if((select count(*) from cte)<=1,null,(select salary from cte order by salary asc limit 1)) as SecondHighestSalary 
*/

# solution-3
select max(salary) as SecondHighestSalary
from employee
where salary < (select max(salary) from employee)
