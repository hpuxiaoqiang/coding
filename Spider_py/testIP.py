import requests
from bs4 import BeautifulSoup
import time
import socket
socket.setdefaulttimeout(3)

url = 'https://www.ipip.net/ip.html'
headers = {
    'User-Agent':' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36'
}
def getIPinfo(res):
    # res = requests.get(url=url,headers=headers)
    soup = BeautifulSoup(res.text,'lxml')
    tb = soup.select('div > table:nth-of-type(1) ')[0]
    tr = tb.find_all('tr')
    ip = tr[1].select('span:nth-of-type(1) > a')[0].get_text()
    address = tr[2].select('td:nth-of-type(2) > span:nth-of-type(1)')[0].get_text()
    return (ip,address)
proxies = []
f  = open('temp','r')
lines = f.readlines()
for i in range(0,len(lines)):
    ip = lines[i].strip("\n")
    proxy_temp = {ip.lower().split(':')[0]: ip.lower()}
    # print(proxy_temp)
    proxies.append(proxy_temp)
f.close()
w = open('Available.txt', 'w')
for proxy in proxies:
    try:
        res = requests.get(url=url,headers=headers,proxies=proxy,timeout=3)
        if res.status_code == 200:
            ip,address = getIPinfo(res)
            if ip != '106.34.112.59':
                print(ip,address,": Available")
                print(proxy['https'])
                w.write(proxy['https']+'\n')
    except Exception as e:
        continue
w.close()