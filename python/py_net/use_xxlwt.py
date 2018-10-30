# -*- coding:utf-8 -*-
import xlwt
book = xlwt.Workbook(encoding='utf-8')
sheet = book.add_sheet('Sheet1')
sheet.write(0,1,'python')
sheet.write(1,1,'none')
book.save('test.xls')