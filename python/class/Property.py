# -*- coding:utf-8 -*-
class Student(object):
    @property
    def birth(self):
        return self.__brith
    @birth.setter
    def birth(self, value):
        self._birth = value
    @property
    def age(self):
        return 2015-self._birth
if __name__ == "__main__":
    stu = Student()
    stu.birth = 1994
    print(stu.age)