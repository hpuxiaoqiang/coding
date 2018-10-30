# -*- coding:utf-8 -*-
class Student(object):
    def __init__(self, name, score):
        self.__name = name
        self.__score = score
    def get_name(self):
        return self.__name
    def get_score(self):
        return self.__score
stu = Student('lijiqiang', 100)
print(stu.get_name(), stu.get_score())