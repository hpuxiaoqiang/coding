# -*- coding:utf-8 -*-
import requests
import re
import time
headers = {
    'User-Agent':' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.100 Safari/537.36'
}
#with open('/home/xiaoqiang/Desktop/python/py_net') as f:
try :
    f = open('/home/xiaoqiang/Desktop/python/py_net/doupo.txt','a+')
except IOError as e:
    print(e)
def get_info(url):
    res = requests.get(url,headers = headers)
    if res.status_code == 200:
        contents = re.findall('<p>(.*?)</p>',res.content.decode('utf-8'),re.S)
        for content in contents :
            f.write(content+'\n')
    else:
        pass
if __name__ == "__main__":
    urls = ['http://www.doupoxs.com/doupocangqiong/{}.html'.format(str(i)) for i in range(2,1665)]
    for url in urls:
        get_info(url)
        time.sleep(2)
    f.close()