# select w1.id from weather w1, weather w2 where w1.temperature>w2.temperature and datediff(w1.recordDate, w2.recordDate)=1;

select w1.id from weather w1 join weather w2 on w1.recordDate = date_add(w2.recordDate, interval 1 day) where w1.temperature > w2.temperature;

# SELECT w1.id
# FROM Weather w1
# JOIN Weather w2 ON w1.recordDate = DATE_ADD(w2.recordDate, INTERVAL 1 DAY)
# WHERE w1.temperature > w2.temperature