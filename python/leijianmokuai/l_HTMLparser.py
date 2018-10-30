# -*- coding:utf-8 -*-
from html.parser import HTMLParser
from html.entities import name2codepoint
from urllib import request
class MyHTMLParser(HTMLParser):
    def __init__(self):
        super(MyHTMLParser,self).__init__()
        self.__parsedata=''
    def handle_starttag(self, tag, attrs):
        if ('class','event-title') in attrs:
            self.__parsedata = 'name'
        if tag == 'time':
            self.__parsedata = 'time'
        if ('class','say-no-more') in attrs:
            self.__parsedata = 'year'
        if ('class','event-location') in attrs:
            self.__parsedata = 'location'
    def handle_endtag(self, tag):
        if tag == 'span' or 'h3':
            self.__parsedata = ''
    def handle_data(self, data):
        if self.__parsedata == 'name':
            print('会议名称：%s'%data)
        if self.__parsedata == 'location':
            print('会议地点：%s'%data)
        if self.__parsedata == 'year':
            print('会议年份：%s'%data)
        if self.__parsedata == 'time':
            print('会议时间：%s'%data)
            print('---------------------')
url = 'https://www.python.org/events/python-events/'
f = request.urlopen(url)
data = f.read()
parser = MyHTMLParser()
parser.feed(data.decode('utf-8'))







# class MyHTMLParser(HTMLParser):
#
#     def handle_starttag(self, tag, attrs):
#         print('<%s>' % tag)
#
#     def handle_endtag(self, tag):
#         print('</%s>' % tag)
#
#     def handle_startendtag(self, tag, attrs):
#         print('<%s/>' % tag)
#
#     def handle_data(self, data):
#         print(data)
#
#     def handle_comment(self, data):
#         print('<!--', data, '-->')
#
#     def handle_entityref(self, name):
#         print('&%s;' % name)
#
#     def handle_charref(self, name):
#         print('&#%s;' % name)
#
# parser = MyHTMLParser()
# parser.feed('''<html>
# <head></head>
# <body>
# <!-- test html parser -->
#     <p>Some <a href=\"#\">html</a> HTML&nbsp;tutorial...<br>END</p>
# </body></html>''')