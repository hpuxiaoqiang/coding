#-*- coding:utf-8 -*-
def consumer():
    r = ''
    while True:
        #遇到yield语句返回，再次执行时从上次返回的yield语句处继续执行。
        n = yield r
        # if not n:
        #     return
        print('[CONSUMER] Consuming %s...' % n)
        r = '200 OK'

def produce(c):
    #这个时候已经启动生成器consumer了
    c.send(None)
    n = 0
    while n < 5:
        n = n + 1
        print('[PRODUCER] Producing %s...' % n)
        #切换到consumer执行
        r = c.send(n)
        print('[PRODUCER] Consumer return: %s' % r)
    c.close()

c = consumer()
produce(c)