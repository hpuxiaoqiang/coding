# -*- coding:utf-8 -*-
import threading
#创建全局ThreadLocal对象
local_school = threading.local()
def process_Student():
    std = local_school.student;
    print("Hello %s(in %s)"%(std,threading.current_thread().name))
def process_Thread(name):
    local_school.student = name
    process_Student()
t1 = threading.Thread(target=process_Thread,args=("Alice",),name='A')
t2 = threading.Thread(target=process_Thread,args=("Bob",),name='B')
t1.start()
t2.start()
t1.join()
t2.join()