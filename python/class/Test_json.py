# -*- coding:utf-8 -*-
import json
import pickle
class Student(object):
    def __init__(self,name,age,score):
        self.name = name
        self.age = age
        self.score = score
def Student2Dict(std):
    return {
        'name':std.name,
        'age':std.age,
        'score':std.score,
    }
S = Student('Bob',20,90)
s=Student2Dict(S)
print(s)
print(json.dumps(S,default=Student2Dict))