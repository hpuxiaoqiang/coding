#-*- coding:utf-8 -*-
import os
from multiprocessing import Process
def run(name):
    print('Run child process %s(%s)..'%(name,os.getpid()))
if __name__ == "__main__":
    print("Parent process %s"%os.getpid())
    p = Process(target=run,args=('test',)) #target 是子进程执行的函数,args是传入的参数
    print("Child Process will start!")
    p.start()
    p.join()
    print('Child Process end')