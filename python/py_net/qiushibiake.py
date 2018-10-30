# -×- coding:utf-8 -*-
import requests
import re
from bs4 import BeautifulSoup

headers = {
    'User-Agent':' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.100 Safari/537.36'
}

info_lists = []

def jungle_sex(class_name):
    if class_name == 'manIcon':
        return 'man'
    else:
        return 'woman'
def get_info(url):
    res = requests.get(url,headers=headers)
    # print(res)
    ids = re.findall('<h2>(.*?)</h2>',res.text,re.S)
    # print(ids)
    levels = re.findall('<div class="articleGender \D+Icon">(.*?)</div>',res.text,re.S)
    # print(levels)
    sexs = re.findall('<div class="articleGender (.*?)">',res.text,re.S)
    # print(sexs)
    contents = re.findall('<span>(.*?)</span>',res.text,re.S)
    # print(contents)
    laughs = re.findall('<span class="stats-vote"><i class="number">(\d+)</i>',res.text,re.S)
    # print(laughs)
    comments = re.findall('<i class="number">(\d+)</i> 评论',res.text,re.S)
    # print(comments)
    for id,level,sex,content,laugh,comment in zip(ids,levels,sexs,contents,laughs,comments):
        info = {
            'id':id,
            'level':level,
            'sex':jungle_sex(sex),
            'content':re.sub('\n','',content),
            'laugh':laugh,
            'comment':comment
        }
        info_lists.append(info)
if __name__ == "__main__":
    urls = ['https://www.qiushibaike.com/8hr/page/{}/'.format(str(i)) for i in range(1,5)]
    for url in urls:
        get_info(url)
    for info_list in info_lists:
        f = open('/home/xiaoqiang/Desktop/python/py_net/qiushi.txt', 'a+')
        try:
            f.write('用户名：\n'),
            f.write(info_list['id']+'\n')
            f.write('等级:\n'),
            f.write(info_list['level']+'\n')
            f.write('性别:\n'),
            f.write(info_list['sex']+'\n')
            f.write('内容:\n'),
            f.write(info_list['content']+'\n')
            f.write('点赞数:\n' ),
            f.write(info_list['laugh']+'\n')
            f.write('评论数\n' )
            f.write(info_list['comment']+'\n')
            f.close()
        except UnicodeEncodeError:
            pass