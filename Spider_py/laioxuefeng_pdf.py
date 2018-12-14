# -*- coding:utf-8 -*-
from __future__ import unicode_literals
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

    #获取网页信息
    def get_webInfo(self,url,headers):
        res = requests.get(url=url,headers=headers)
        return res

    def get_menu_url_list(self,res):
        soup = BeautifulSoup(res.content,'html.parser')
        # 通过select得到左侧目录栏
        ul = soup.select('#x-wiki-index')[0]
        # 通过观察目录结构发现每一小节的链接和名字都在a标签下,提取所有目录a标签,放入li中
        li = ul.find_all("a")
        for a in li:
            href = a.get("href")
            # title = a.get_text().strip()
            url = self.domain+href
            # 所有文章的url
            self.url_list.append(url)

    def get_content(self,res):
        soup = BeautifulSoup(res.content, 'html.parser')
        # soup.new_tag()
        content = soup.find_all(class_='x-wiki-content')[0]
        content = str(content)
        print(content)
        # print(type(content),type(html_template))
        html = html_template.format(content)
        print(html)
        try:
            f = open('index.html', 'w', encoding='utf-8')
            f.write(html)
        except:
            raise IOError
    def Trans_to_PDF(self):
        pass
    def run(self):
        pass
if __name__ == "__main__":
    pass





#####demo###



url = 'https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000/001431608990315a01b575e2ab041168ff0df194698afac000'
headers = {
    'User-Agent':' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36'
}

def get_list():
    res = requests.get(url=url,headers = headers)
    soup = BeautifulSoup(res.content,'html.parser')
    # 通过select得到左侧目录栏
    ul = soup.select('#x-wiki-index')[0]
    # 通过观察目录结构发现每一小节的链接和名字都在a标签下,提取所有目录a标签,放入li中
    li = ul.find_all("a")
    #遍历li,得到每一小节的部分链接和标题
    for a in li:
        href = a.get("href")
        title = a.get_text().strip()
        ur = 'https://www.liaoxuefeng.com'+href
        # print('href:',href,'title:',title,'\n')
        print(title,ur)
def get_content():
    res = requests.get(url=url, headers=headers)
    soup = BeautifulSoup(res.content, 'html.parser')
    content = soup.find_all(class_='x-wiki-content')[0]

    #在第1行插入标题
    title = soup.find('h4').get_text()
    center_tag = soup.new_tag("center")
    title_tag = soup.new_tag('h1')
    title_tag.string = title
    center_tag.insert(0, title_tag)
    content.insert(0, center_tag)

    content = str(content)
    print(content)
    # 因为通过爬下来的网页,<a>标签下图片src的显示信息为一个加载的图标
    # 而真正的图片URL藏在data-src下,因此通过正则表达式将爬下来的网页中的src内容换为data-src中的内容

    re_img_url = "(<img .*? data-src=\")(.*?)(\") (src=\")(.*?)(\"/>)"
    def fun(m):
        if m.group(2) != m.group(5):
            img_url = "".join([m.group(1),m.group(2),m.group(3),m.group(4),m.group(2),m.group(6)])
            return img_url
        else:
            img_url = "".join([m.group(1), m.group(2), m.group(3), m.group(4), m.group(5), m.group(6)])
            return img_url

    # content = re.compile(re_img_url).sub(fun,content)

    html = html_template.format(content)
    html = str(html)
    try:
        f = open('index.html','w',encoding='utf-8')
        f.write(html)
    except:
        raise IOError
# get_list()
get_content()
# src="https:s//cdn.liaoxuefeng.com/cdn/files/attachments/00138676512923004999ceca5614eb2afc5c0efdd2e4640000/0"
def TransToPDF():
    try:
        f = open('index.html','r',encoding='utf-8')
        html = f.read()
        # print(html)
    except:
        raise IOError
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
    pdfkit.from_file('index.html', 'demo' + ".pdf", options=options)

