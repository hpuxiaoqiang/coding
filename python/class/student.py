# -*- coding:utf--8 -*-
import unittest
class Student(object):
    def __init__(self, name, score):
        self.name = name
        self.score = score
    def get_grade(self):
        if self.score >= 80 and self.score <= 100:
            return 'A'
        if self.score >= 60 and self.score < 80:
            return 'B'
        if self.score >=0 and self.score < 60:
            return 'C'
        else:
            raise ValueError
