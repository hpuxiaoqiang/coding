# -*- coding:utf-8 -*-
import requests
from lxml import etree
headers = {
    'User-Agent':' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.100 Safari/537.36'
}
res = requests.get('https://www.qiushibaike.com/text/',headers = headers)
html = etree.HTML(res.text)
#原本想用'div[@class="article block untagged mb15 typs_long"]'抓取每个用户单独所属板块，但由于添加了typs，导致不统一
#就改用'//*[@id="content-left"]'抓取当前页包含用户信息的一个大板块
ids = html.xpath('//*[@id="content-left"]')
infos = ids[0].xpath('//*/div[1]/a[2]/h2/text()') #从这个大板块里面根据xpath，抓取到对应位置的id信息
print(infos)
for id in infos:
    print(id)
