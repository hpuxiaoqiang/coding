# -*- coding:utf-8 -*-
import logging
import os
import time
import re
from urllib.parse import urlparse
import requests
import pdfkit
from bs4 import BeautifulSoup

# 构建一个HTML文件,将文章内容放进去
html_template = """
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
</head>
<body>
 {} 
</body>
</html>
"""
class Spider_For_LiaoXueFeng(object):

    def __init__(self,book_name,start_url,headers):
        self.book_name = book_name
        self.start_url = start_url
        self.headers = headers
        # 得到分离出主域名
        self.domain = '{ur.scheme}://{ur.netloc}'.format(ur=urlparse(self.start_url))
        self.url_list = []
        self.name_list = []

    #获取网页信息
    def get_webInfo(self,url, **kw):
        res = requests.get(url=url,headers=self.headers,proxies=kw)
        return res

    def get_menu_url_list(self,res):
        soup = BeautifulSoup(res.content,'html.parser')
        # 通过select得到左侧目录栏
        ul = soup.select('#x-wiki-index')[0]
        # 通过观察目录结构发现每一小节的链接和名字都在a标签下,提取所有目录a标签,放入li中
        li = ul.find_all("a")
        for a in li:
            href = a.get("href")
            title = a.get_text().strip()
            url = self.domain+href
            # 所有文章的url和文章标题
            self.url_list.append(url)
            self.name_list.append(title)

    def get_content(self,res):
        if res.status_code != 200:
            return 'Current page error!'
        soup = BeautifulSoup(res.content, 'html.parser')

        content = soup.find_all(class_='x-wiki-content')[0]

        # 在第1行插入标题
        title = soup.find('h4').get_text()
        center_tag = soup.new_tag("center")
        title_tag = soup.new_tag('h2')
        title_tag.string = title
        center_tag.insert(0, title_tag)
        content.insert(0, center_tag)

        content = str(content)
        # print(content)
        # 因为通过爬下来的网页,<a>标签下图片src的显示信息为一个加载的图标
        # 而真正的图片URL藏在data-src下,因此通过正则表达式将爬下来的网页中的src内容换为data-src中的内容

        re_img_url = "(<img .*? data-src=\")(.*?)(\") (src=\")(.*?)(\"/>)"

        # m相当于re.search(re_img_url,content)的结果
        def fun(m):
            if m.group(2) != m.group(5):
                img_url = "".join([m.group(1), m.group(2), m.group(3), m.group(4), m.group(2), m.group(6)])
                return img_url
            else:
                img_url = "".join([m.group(1), m.group(2), m.group(3), m.group(4), m.group(5), m.group(6)])
                return img_url

        # re.sub还允许使用函数对匹配项的替换进行复杂的处理,函数的传入参数既匹配到的group
        #  写法等价 re.sub(r'(<img .*? data-src=\")(.*?)(\") (src=\")(.*?)(\"/>)',fun,content)
        content = re.compile(re_img_url).sub(fun, content)

        html = html_template.format(content)
        html = str(html)
        return html
    def removeHtml(self,htmls_name):
        # 转换为PDF后删除所有的HTML文件
        for html in htmls_name:
            os.remove(html)
    def Trans_to_PDF(self,filenames):
        options = {
            'page-size': 'Letter',
            'margin-top': '0.75in',
            'margin-right': '0.75in',
            'margin-bottom': '0.75in',
            'margin-left': '0.75in',
            'encoding': "UTF-8",
            'custom-header': [
                ('Accept-Encoding', 'gzip')
            ],
            'cookie': [
                ('cookie-name1', 'cookie-value1'),
                ('cookie-name2', 'cookie-value2'),
            ],
            'outline-depth': 10,
        }
        pdfkit.from_file(filenames, self.book_name + ".pdf", options=options)
    def run(self):
        startTime = time.time()
        htmls_name = []
        # 获取ip列表
        f = open('Available.txt', 'r')
        lines = f.readlines()
        i = 0
        ip = lines[i].strip("\n")
        proxy = {ip.lower().split(':')[0]: ip.lower()}
        # 这个只request一次
        self.get_menu_url_list(self.get_webInfo(self.start_url,proxies=proxy))
        # 获取目录后睡眠5秒
        time.sleep(5)

        # request多次会封ip,因此要更换ip
        for filename,url in zip(self.name_list,self.url_list):
            if i == len(lines):
                break
            ip = lines[i].strip("\n")
            proxy = {ip.lower().split(':')[0]: ip.lower()}
            #  获取当前章节网页信息
            res = self.get_webInfo(url,proxies=proxy)
            if res.status_code != 200:
                i = i+1
                continue
            # 解析网页，得到文章内容
            html = self.get_content(res)
            # print(html)
            htmls_name.append(filename+'.html')
            try :
               f = open(filename+'.html','w')
               f.write(html)
            except IOError as e:
               print(e)
            print(filename,':complete')
            # 每爬完一章睡眠5秒
            time.sleep(5)
        self.Trans_to_PDF(htmls_name)
        total_time = time.time() - startTime
        print('总耗时为：',total_time)
if __name__ == "__main__":
    url = 'https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000'
    headers = {
        'User-Agent': ' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36'
    }
    demo = Spider_For_LiaoXueFeng(book_name='demo',start_url=url,headers=headers)
    demo.run()
