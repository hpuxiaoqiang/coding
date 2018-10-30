# -*- coding:utf-8 -*-
from email.mime.text import MIMEText
from email.header import Header
msg = MIMEText('Hello ,sent by python ....','plain','utf-8')
from_addr = input('From:')
password = input('password:')
to_addr = input('to server :')
smtp_server = input('SMTP server:')
msg['From'] = from_addr
msg['To'] = to_addr
msg['Subject'] = Header('来自SMTP的问候...','utf-8').encode()
import smtplib
server = smtplib.SMTP(smtp_server,25)
server.set_debuglevel(1)
server.login(from_addr,password)
server.sendmail(from_addr,[to_addr],msg.as_string())
server.quit()