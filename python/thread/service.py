# -*- coing :utf-8 -*-
import time
import random
import threading
from multiprocessing.managers import BaseManager
import queue
task_queue = queue.Queue()
result_Queue = queue.Queue()
class QueueManger(BaseManager):
    pass
QueueManger.register('get_task_queue',callable=lambda:task_queue)
QueueManger.register('get_result_queue',callable=lambda:result_Queue)
manager = QueueManger(address=('',5000),authkey=b'abcd')
manager.start()
task = manager.get_task_queue()
result = manager.get_result_queue()
for i in range(10):
    n = random.randint(0,10000)
    print('put task %d...'%n)
    task.put(n)
print('try get result...')
for i in range(10):
    r = result.get(timeout=10)
    print('result:%s'%r)
manager.shutdown()
print('master exit...')