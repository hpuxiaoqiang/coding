# -*- coding:utf-8 -*-
import requests
from bs4 import BeautifulSoup
url = 'https://www.xicidaili.com/nn/1'
headers = {
    'User-Agent':' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36'
}
res = requests.get(url=url,headers=headers)
soup = BeautifulSoup(res.content,'lxml')
f = open('temp','w')
ips = soup.find_all('tr')
for i in range(1,len(ips)):
    ip = ips[i]
    tds = ip.find_all('td')
    ip_temp = tds[5].contents[0]+'://'+tds[1].contents[0]+":"+tds[2].contents[0]+"\n"
    f.write(ip_temp)
f.close()