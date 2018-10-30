# -*- coding:utf-8 -*-
import os
print('process(%s) start'%os.getpid())
pid = os.fork()#创建子进程，分别在子进程和父进程中返回
if pid==0 :#子进程返回的是0
    print('I am child process(%s),my father is process(%s)'%(os.getpid(),os.getppid()))
else:
    print('I(%s) just created a child process(%s)' % (os.getpid(), pid))