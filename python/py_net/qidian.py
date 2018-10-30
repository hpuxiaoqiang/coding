# -*- coding:utf-8 -*-
import csv
import os
from lxml import etree
from multiprocessing import Pool
import time
import requests
headers = {
    'User-Agent': ' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.100 Safari/537.36'
}
#存放所有的信息，超级耗内存，很容易爆炸
# all_page_info_lists = []
def get_urls(url,page):
    page_info_lists = []#存放每一页的信息
    res = requests.get(url,headers = headers)
    html = etree.HTML(res.text)
    #得到每一本书的大标签
    infos = html.xpath('/html/body/div[2]/div[5]/div[2]/div[2]/div/ul/li')
    for info in infos:
        title = info.xpath('div[2]/h4/a/text()')[0]
        author = info.xpath('div[2]/p[1]/a[1]/text()')[0]
        style1 = info.xpath('div[2]/p[1]/a[2]/text()')[0]
        style2 = info.xpath('div[2]/p[1]/a[3]/text()')[0]
        status = info.xpath('div[2]/p[1]/span/text()')[0]
        #书籍简介
        # discribe = info.xpath('div[2]/p[2]/text()')[0].strip()
        info_list = [title,author,style1,style2,status]
        #all_page_info_lists.append(info_list) 加入当前页信息到所有信息
        #存放当前页信息
        page_info_lists.append(info_list)
    print("prosess %s page: "%os.getpid(),page," complete")
    return page_info_lists
def run(name,n):
    print('Run task %s (%s)...' % (name, os.getpid()))
    page = (n-1)*10
    start = time.time()
    #每10页一次
    urls = ['https://www.qidian.com/all/?page={}'.format(str(i)) for i in range((n-1)*10, n*10)]
    header = ['title', 'author', 'style1', 'style2', 'status']
    # csv方式存储
    fp = open('/home/xiaoqiang/Desktop/python/py_net/qidian_book{}.csv'.format(str(n)), 'w+')
    writer = csv.writer(fp)
    writer.writerow(header)
    # 遍历每一页
    for url in urls:
        page_info_lists = get_urls(url,page)
        # 遍历每一页的信息
        for simple_info in page_info_lists:
            writer.writerow(simple_info)  # 存储每一条信息
        page += 1
    end = time.time()
    print("%s run time:"%os.getpid(), end - start)
if __name__ == "__main__":
    #多进程
    p = Pool(4)
    for i in range(1,5):
        #args 给进程运行的函数传入的参数，其中通过i来指定爬取的页码到哪
        p.apply_async(run,args=(i,i))
    p.close()
    p.join()
    print('All subprocesses done.')
    #excel方式存储
    # book = xlwt.Workbook(encoding='utf-8')
    # sheet = book.add_sheet("Sheet1")
    # for i in range(len(header)):
    #     sheet.write(0,i,header[i])
    # row = 1
    # for url in urls:
    #     #每一页的数据条数
    #     get_urls(url)
    #     page+=1
    #     #遍历每一页数据
    # for info in all_page_info_lists:
    #     rank = 0
    #     #写入每一本书的数据
    #     for data in info:
    #         sheet.write(row,rank,data)
    #         rank += 1 #列数加一
    #     row +=1
    # book.save("qidian.xls")
    # end = time.time()
    # print("time:",end-start)