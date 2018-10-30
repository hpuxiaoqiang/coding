# -*- coding:utf-8 -*-
import os
def Search(FileName,path=os.curdir):
    for x in os.listdir(path):
        if os.path.isdir(x):
            Search(FileName,os.path.join(path,x))
        elif x.find(FileName)!= -1:
            print(os.path.realpath(x))
Search("try")