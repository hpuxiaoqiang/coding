# -*- coding:utf-8 -*-
import re
from datetime import datetime,timezone,timedelta
re_t = re.compile(r'^UTC(\-|\+)([0-9]|0[0-9]|1[0-2])\:00$')
def totimestamp(dt_str,tz_str):
    time = datetime.strptime(dt_str,'%Y-%m-%d %H:%M:%S')
    m = re.match(re_t, tz_str)
    flag = m.group(1)
    tz_hours = m.group(2)
    if flag == '+':
        #创建时区，因为datetime的时区tzinfo默认为none，无法区分时区，如果直接使用timestamp函数就会默认使用当前电脑时区
        tz_utc = timezone(timedelta(hours=int(tz_hours)))
        #错误的想法：然后用timestamp函数想的是直接用时间减去时区，但没有考虑到datetime的默认时区问题
        # time = time-timedelta(hours=int(tz_hours))
    elif flag == '-':
        # 创建时区
        tz_utc = timezone(timedelta(hours=-int(tz_hours)))
        # time = time+timedelta(hours=int(tz_hours))
    #修改datetime的时区，避免timestamp函数使用当前电脑时区
    retime = time.replace(tzinfo=tz_utc)
    utc_time = datetime.timestamp(retime)
    print('%s,%s to UTC+0 is:'%(dt_str,tz_str))
    print(utc_time)

totimestamp('2015-6-1 08:10:30','UTC+7:00')
totimestamp('2015-6-1 09:10:30','UTC+08:00')
totimestamp('2015-6-1 13:10:30','UTC+12:00')
totimestamp('2015-5-31 16:10:30','UTC-9:00')