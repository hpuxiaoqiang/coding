#-*- coding:utf-8 -*-
from multiprocessing import Pool
import os
import time
import random
def run(name):
    print("Run task%s(%s)"%(name,os.getpid()))
    start = time.time()
    time.sleep(random.random()*3)
    end = time.time()
    print("task %s run (%s) seconds"%(name,(end-start)))
if __name__ == "__main__":
    print("Parent Process %s ."%os.getpid())
    p = Pool(4)
    for i in range(5):
        p.apply_async(run,args=(i,))
    print("waiting for all subprocess done...")
    p.close()
    p.join()
    print("All subprocess done..")