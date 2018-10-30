# -*- coding:utf-8 -*-
import os
def ShowFile():
    for x in os.listdir('.'):
        if os.path.isfile(x):
            print(x)