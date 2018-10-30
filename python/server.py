# -*- coding:utf-8 -*-
from hello import application
from wsgiref.simple_server import make_server
httpd = make_server('',9000,application)
print('Server httpd running on port 9000...')
httpd.serve_forever()