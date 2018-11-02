# -*- coding:utf-8 -*-
import time
import requests
import csv
import json
import urllib.parse
from bs4 import BeautifulSoup

headers = {
    'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8',
    'user-agent':' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36'
}
#创建csv文件
fp = open('/home/xiaoqiang/Documents/git_file/Spider_py/糗事百科用户地址信息.csv','wt',encoding='utf-8',newline='')
writer = csv.writer(fp)
#写入标题
writer.writerow(('user_name','adress','longitude','latitude','user_url'))

def get_jingweidu(address):
    url = 'https://restapi.amap.com/v3/geocode/geo?'
    #结构化地址信息
    #高德Key
    mykey = '2966420ffd95dffb3c5a93ce725ab19a'
    #返回数据格式类型
    output = 'JSON'
    myurl  = url + 'address=' + urllib.parse.quote(address)+'&output='+output+'&key='+mykey
    web_data = requests.get(myurl,headers = headers)
    #返回网页得到的json信息
    json_data = json.loads(web_data.text)
    #得到经纬度信息
    location = json_data.get('geocodes')
    if location:
        location = location[0].get('location').split(',')
        return location
    else:
        return ['坐标为空','坐标为空']

def get_user_address(user_url):
    res = requests.get(user_url,headers)
    soup = BeautifulSoup(res.text,'lxml')
    user_name = soup.select('div.user-header > div > h2')[0].get_text()
    #如果用户隐藏了个人信息页就打印“当前用户已关闭糗百个人动态”
    if soup.select('div.user-col-all'):
        user_hide = soup.select('#editInfo > h3')[0].get_text()
        print('用户：',user_name,'状态：',user_hide)
    else:
        #用户开放了个人界面，但是地址信息不一定有
        user_address = soup.select('div.user-col-left > div:nth-of-type(2) > ul > li:nth-of-type(4)')[0].get_text().split(':')[-1]
        if user_address != '故乡':
            user_address = user_address.split(' · ')
            print('用户：', user_name, '地址：', user_address)
            location = get_jingweidu(user_address[-1])
            try:
                writer.writerow((user_name,user_address,location[0],location[1],user_url))
            except IndexError:
                pass
        else:
            pass
def get_user_url(url):
    url_part = 'https://www.qiushibaike.com'
    res = requests.get(url,headers=headers)
    soup = BeautifulSoup(res.text,'lxml')
    #从当前页里面得到用户id链接
    user_urls = soup.select('div.author.clearfix > a:nth-of-type(1)')
    for user_url in user_urls:
        user_part_url = user_url.get('href')
        print(url_part+user_part_url)
        # time.sleep(2)
        get_user_address(url_part+user_part_url)
if __name__ == "__main__":
    urls = ['https://www.qiushibaike.com/8hr/page/{}/'.format(str(i) )for i in range(1,11)]
    for url in urls:
        get_user_url(url)
        # time.sleep(2)
# get_user_address('https://www.qiushibaike.com/users/39909372/')
# get_user_address('https://www.qiushibaike.com/users/28326980/')
