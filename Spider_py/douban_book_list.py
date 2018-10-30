# -*- coding:utf-8 -*-
from lxml import etree
import csv
import requests
with open('/home/xiaoqiang/Desktop/python/py_net/douban_book_top250.csv','wt',newline='',encoding='utf-8') as f:
    writer = csv.writer(f)
    writer.writerow(('name','url','author','publisher','date','price','rate','comment'))
    urls = ['https://book.douban.com/top250?start={}'.format(str(i)) for i in range(0,250,25)]
    headers = {
        'User-Agent': ' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.100 Safari/537.36'
    }
    for url in urls :
        res = requests.get(url,headers=headers)
        html = etree.HTML(res.text)
        infos = html.xpath('//tr[@class = "item"]')#选择每一本书的大标签
        print(len(infos))
        for info in infos:
            name= info.xpath('td/div/a/@title')[0]
            url = info.xpath('td/div/a/@href')[0]
            book_infos = info.xpath('td/p/text()')[0]
            author = book_infos.split('/')[0]
            publisher = book_infos.split('/')[-3]
            date = book_infos.split('/')[-2]
            price = book_infos.split('/')[-1]
            rate = info.xpath('td/div/span[2]/text()')[0]
            comments = info.xpath('td/p/span/text()')
            comment = comments[0] if len(comments) != 0 else "NONE"
            writer.writerow((name,url,author,publisher,date,price,rate,comment))