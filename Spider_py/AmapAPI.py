# -*- coding:utf-8 -*-
import requests
import urllib.parse
import json


headers = {
    'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8',
    'user-agent':' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36'
}
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
        print(location)
    else:
        print('坐标无返回')
address = input('输入要查询的地点:\n')
get_jingweidu(address)
#返回的信息样例
# {'info': 'OK',
#  'status': '1',
#  'count': '1',
#  'geocodes':
#      [
#          {'citycode': '010',
#           'neighborhood': {'type': [], 'name': []},
#           'building': {'type': [], 'name': []},
#           'number': [],
#           'district': [],
#           'city': '北京市',
#           'township': [],
#           'location': '116.407526,39.904030',
#           'formatted_address': '北京市',
#           'level': '省',
#           'country': '中国',
#           'adcode': '110000',
#           'street': [],
#           'province': '北京市'}],
#  'infocode': '10000'}