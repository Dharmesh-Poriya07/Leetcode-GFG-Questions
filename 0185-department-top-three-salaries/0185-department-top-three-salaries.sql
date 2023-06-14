
with cte as(
  select e.name as Employee, e.salary as Salary, d.name as Department,dense_rank() over(partition by d.name order by e.salary desc) as ranks
  from employee e
  inner join department d
  on e.departmentId=d.id
)

select Department, Employee, Salary from cte where ranks<=3;
