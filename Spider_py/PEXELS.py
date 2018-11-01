# -*- coding；utf-8 -*-
import requests
import time
import re
from baidu_translate import Translate
from bs4 import BeautifulSoup
headers = {
    'accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8',
    'user-agent':' Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.77 Safari/537.36'
}
#得到当前页图片下载链接
def get_photo_download_url(url):
    web_data = requests.get(url,headers = headers)
    print(web_data.status_code)
    soup = BeautifulSoup(web_data.text,'lxml')
    #得到缩略图的下载链接
    # imgs = soup.select('article > a > img')
    #得到下载高清图的链接,下载较慢
    imgs = soup.select('article > a:nth-of-type(2)')
    #图片下载链接list
    list = []
    for img in imgs :
        photo = img.get('href')
        list.append(photo)
    #返回当前页图片下载链接
    return list
#下载图片
def save_photo(photo_download_url):
    #图片保存路径
    save_path = '/home/xiaoqiang/Pictures/pexels_photo/'
    #遍历每一个链接下载图片
    for item in photo_download_url:
         data = requests.get(item,headers=headers)
         fp = open(save_path+'pexels-photo-'+item.split('?')[0][-10:],'wb')
         fp.write(data.content)
         fp.close()
         print('pexels-photo-'+item.split('?')[0][-10:]+'已经下载完成')
         time.sleep(1)#睡眠1秒

if __name__ == "__main__":
    url_path = 'https://www.pexels.com/search/'
    zh_words = input('输入你要下载的图片类型：')
    # 利用百度翻译api将中文关键词转换为英文
    en_words = Translate(zh_words).trans()
    # 构建搜索结果页链接(page=1)
    url = url_path + en_words + '/'
    print(url)
    # 得到搜索结果页信息(page=1)
    web_data = requests.get(url, headers=headers)
    print(web_data.status_code)
    #得到当前分类最大页书
    num = re.findall('page=(\d+)', web_data.text, re.S)
    max_page_num = max(int(i) for i in num)
    page = input('输入下载的页数(1-%d)：' % max_page_num)
    for i in range(1,int(page)+1):
        #得到当前页链接
        c_url = url+'?page='+str(i)
        photo_list = get_photo_download_url(c_url)
        save_photo(photo_list)
        print('第%d页图片下载完成'%i)

#通过结果发现每次链接只能够爬15张照片
#观察网页源代码，我们发现了下列部分代码,而且其中包含了最大页数
#<div class="pagination"><a class="previous_page" rel="prev" href="/search/water/?page=3">&#8592; Previous</a> <a href="/search/water/?page=1">1</a> <a href="/search/water/?page=2">2</a> <a rel="prev" href="/search/water/?page=3">3</a> <em class="current">4</em> <a rel="next" href="/search/water/?page=5">5</a> <a href="/search/water/?page=6">6</a> <a href="/search/water/?page=7">7</a> <a href="/search/water/?page=8">8</a> <a href="/search/water/?page=9">9</a> <span class="gap">&hellip;</span> <a href="/search/water/?page=533">533</a> <a href="/search/water/?page=534">534</a> <a class="next_page" rel="next" href="/search/water/?page=5">Next &#8594;</a></div>
# 其中有href="/search/water/?page=3",这样的代码
#然后构建了https://www.pexels.com/search/water/?page=3,发现依旧可以访问,而且刚好显示15张图片,以此来构造链接就可以爬更多的照片了