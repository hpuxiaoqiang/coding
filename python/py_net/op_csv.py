# -*- coding:utf-8 -*-
import csv
with open('/home/xiaoqiang/Desktop/python/py_net/test.csv','w+') as f:
    writer = csv.writer(f)
    ls = ('id','name')
    writer.writerow(ls)
    writer.writerow(('1', 'zhangsan'))
    writer.writerow(('2', 'san'))
    writer.writerow(('3', 'ok'))