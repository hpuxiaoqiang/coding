# -*- coding:utf-8 -*-
import requests
import re
from bs4 import BeautifulSoup
from lxml import etree
import time

headers = {
    'User-Agent': ' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.100 Safari/537.36'
}

urls = ['https://www.qiushibaike.com/text/page/{}/'.format(str(i)) for i in range(1,10)]
def res_scraper(url):
    print("into1")
    res = requests.get(url,headers=headers)
    print(res.status_code)
    ids = re.findall('<h2>(.*?)</h2>',res.text,re.S)
    print(ids)
    contents = re.findall('<span>(.*?)</span>', res.text, re.S)
    laughs = re.findall('<span class="stats-vote"><i class="number">(\d+)</i>', res.text, re.S)
    comments = re.findall('<i class="number">(\d+)</i> 评论', res.text, re.S)
    for id,content,laugh,comment in zip(ids,contents,laughs,comments):
        info = {
            'id':id,
            'content':re.sub('\n','',content),
            'laugh':laugh,
            'comment':comment
        }
        print(info)

def bs_scraper(url):
    print("into2")
    res = requests.get(url,headers = headers)
    soup = BeautifulSoup(res.text,'lxml')
    ids = soup.select('a > h2')
    contents = soup.select('a.contentHerf > div > span')#qiushi_tag_121178480 >
    laughs = soup.select('div.stats > span.stats-vote > i')#qiushi_tag_121178480 >
    comments = soup.select('i.number')
    for id,content,laugh,comment in zip(ids,contents,laughs,comments):
        info = {
            'id':id.get_text(),
            'content':content.get_text(),
            'laugh':laugh.get_text(),
            'comment':comment.get_text()
        }
        print(info)

def lxml_scraper(url):
    print("into3")
    res = requests.get(url, headers=headers)
    html = etree.HTML(res.text)
    user_infos = html.xpath('//*[@id="content-left"]')
    try:
        ids = user_infos[0].xpath('//*/div[1]/a[2]/h2/text()')
        contents = user_infos[0].xpath('//*/a[1]/div/span/text()')
        laughs = user_infos[0].xpath('//*/div[2]/span[1]/i/text()')
        comments = user_infos[0].xpath('//*/i/text()')
        for id,content,laugh,comment in zip(ids,contents,laughs,comments):
            info ={
                'id': id,
                'content': content,
                'laugh': laugh,
                'comment': comment
            }
            print(info)
    except IndexError:
        pass
if __name__ =="__main__":
    for name,scraper in [('Regularexpressions',res_scraper),('BeautifulSoup',bs_scraper),('Lxml',lxml_scraper)]:
        start = time.time()
        for url in urls:
            print(url)
            scraper(url)
        end = time.time()
        print(name,end-start)