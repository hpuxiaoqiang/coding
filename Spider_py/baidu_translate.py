# -*- coding:utf-8 -*-
import requests
import hashlib
import random
import urllib.parse
import json
#将翻译功能封装
#words必传参数,为需要翻译的文字
#fromlang为待翻译文字语言,默认为zh
#tolang为翻译后文字语言,默认为en
#对实例对象调用trans()方法就得到了翻译后的文字
class Translate(object):
    def __init__(self,words,fromlang='zh',tolang='en'):
        self.fromlang = fromlang
        self.tolang = tolang
        self.words = words
        self.__url = 'http://api.fanyi.baidu.com/api/trans/vip/translate'
        self.__appid = '20181031000227870'
        self.__secretkey = 'LT7E13JNfg9IFQCG5nHb'
        self.__salt = random.randint(32768, 65536)
        self.__md5key = hashlib.md5()
    def __get_sign(self):
        #得到我的sign串
        self.__sign = self.__appid+self.words+str(self.__salt)+self.__secretkey
        #计算我的sign串的md5值
        self.__md5key.update(self.__sign.encode('utf-8'))
        #构造翻译当前文字的URL
        myurl = self.__url + '?q=' + \
                urllib.parse.quote(self.words) \
                + '&from=' + self.fromlang \
                + '&to=' + self.tolang \
                + '&appid=' + self.__appid \
                + '&salt=' + str(self.__salt) \
                + '&sign=' + self.__md5key.hexdigest()
        return myurl
    def trans(self):
        res = requests.get(self.__get_sign())
        json_data = json.loads(res.text)
        dst = json_data.get("trans_result")[0].get("dst")
        #返回翻译结果
        return dst

# fromlang = 'zh'
# tolang = 'en'
# url = 'http://api.fanyi.baidu.com/api/trans/vip/translate'
# appid = '20181031000227870' #appid
# secretkey = 'LT7E13JNfg9IFQCG5nHb' #秘钥
# salt = random.randint(32768,65536)
# q = input('请输入需要翻译的文字：\n') #需要翻译的文字
# sign = appid+q+str(salt)+secretkey
# md5key = hashlib.md5()
# md5key.update(sign.encode('utf-8'))
# # print(md5key.hexdigest())
# myurl = url+'?q='+urllib.parse.quote(q)+'&from='+fromlang+'&to='+tolang+'&appid='+appid+'&salt='+str(salt)+'&sign='+md5key.hexdigest()
# print(myurl)
# res = requests.get(myurl)
# print(res.text)
# json_data = json.loads(res.text)
# print(json_data.get("trans_result")[0].get("dst"))
# # print(json_data.get("trans_result").get("dst"))
