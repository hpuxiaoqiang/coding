# -*- coding: utf-8 -*-
'''
with open('/home/xiaoqiang/Desktop/python/testio.txt','r') as f:
    for line in f.readlines():
        print(line)
'''

try:
    f = open('/home/xiaoqiang/Desktop/python/testio.txt','r')
    # f.write("Hello,World!")
    print(f.read())

except IOError as e:
    print('IoError:',e)
finally:
    f.close()
