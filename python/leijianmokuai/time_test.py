# -*- coding:utf-8 -*-
from datetime import datetime,timedelta,timezone
#获得当前日期和时间
now = datetime.now()
print(now)
#指定日期和时间
dt = datetime(2018,5,20,13,14)
#datetime to timestamp
print(dt.timestamp())
#timestamp to datetime
stamp = 1526793240
print(datetime.fromtimestamp(stamp))
#time + or -
print(now+timedelta(hours=10))
print(now+timedelta(days=1))
print(now+timedelta(days=1,hours=2,seconds=3))
#local to utc_time
tz_utc_8 = timezone(timedelta(hours=8))
now2 = datetime.now()
print(now2)
#timezone change
utc_date = datetime.utcnow().replace(tzinfo=timezone.utc)
print(utc_date)
bj_dt = utc_date.astimezone(timezone(timedelta(hours=8)))
print(bj_dt)
tokyo_dt = utc_date.astimezone(timezone(timedelta(hours=9)))
print(tokyo_dt)