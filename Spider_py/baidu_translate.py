# -*- coding:utf-8 -*-
import requests
import hashlib
import random
import urllib.parse
import json
fromlang = 'zh'
tolang = 'en'
url = 'http://api.fanyi.baidu.com/api/trans/vip/translate'

appid = '20181031000227870' #appid
secretkey = 'LT7E13JNfg9IFQCG5nHb' #秘钥
salt = random.randint(32768,65536)
q = input('请输入需要翻译的文字') #需要翻译的文字
sign = appid+q+str(salt)+secretkey
md5key = hashlib.md5()
md5key.update(sign.encode('utf-8'))
# print(md5key.hexdigest())
myurl = url+'?q='+urllib.parse.quote(q)+'&from='+fromlang+'&to='+tolang+'&appid='+appid+'&salt='+str(salt)+'&sign='+md5key.hexdigest()
res = requests.get(myurl)
print(res.text)
json_data = json.loads(res.text)
print(json_data.get("trans_result"))

