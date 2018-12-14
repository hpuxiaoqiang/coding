# -*- coding:utf-8 -*-
import requests
import pymysql
from bs4 import BeautifulSoup
import re
headers = {
    'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.102 Safari/537.36'
}

def save_to_mysql(title,url,info):
    db = pymysql.connect('localhost','root','123456','Top250')
    cursor = db.cursor()
    sql = "INSERT INTO Info VALUES(\"%s\",\"%s\",\"%s\")"%(str(title),str(url),str(info))
    print(sql)
    # sql = """"""
    cursor.execute(sql)
    db.commit()
    db.close()

def get_music_info(url):
    # 存放当前页里面每一首歌的名字
    music_names = []
    # 存放当前页里面每一首歌的链接
    music_urls = []
    # 存放当前页里面每一首歌的info
    music_info = []
    res = requests.get(url,headers=headers)
    print(res.status_code)
    soup = BeautifulSoup(res.text,'lxml')
    # content > div > div.article > div > table:nth-child(2) > tbody > tr > td:nth-child(2) > div > a
    # content > div > div.article > div > table:nth-child(2) > tbody > tr > td:nth-child(2) > div > p
    #当前页包含歌曲信息的所有<a>标签
    music_hrefs = soup.select('tr > td:nth-of-type(2) > div > a')
    # 当前页包含歌曲信息的所有<p>标签
    music_infos = soup.select('tr > td:nth-of-type(2) > div > p')
    for murl in music_hrefs:
        # print(murl.get('href'))
        #将当前页的歌曲名字加入到music_name里面
        music_names.append(murl.get_text().replace('\n','').replace('                ','||').strip())
        # 加入将到music_urls里面
        music_urls.append(murl.get('href'))
    for minfo in music_infos:
        minfo = minfo.get_text().strip()
        music_info.append(minfo)
    for title,url,info in zip(music_names,music_urls,music_info):
        # data = {
        #     'title':title,
        #     'url':url,
        #     'info':info
        # }
        save_to_mysql(title,url,info)

get_music_info('https://music.douban.com/top250?start=25')


