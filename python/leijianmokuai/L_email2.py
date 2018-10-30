# -*- coding:utf-8 -*-
from email import encoders
from email.header import Header
from email.mime.text import MIMEText
from email.utils import parseaddr,formataddr
import smtplib
def _format_addr(s):
    name,addr = parseaddr(s)
    return formataddr((Header(name,'utf-8').encode(),addr))
from_addr = input('From:')
password = input('Password:')
to_addr = input('to_addr:')
smtp_server = input('Smtp_server:')
msg = MIMEText('Hello,send by python...','plain','utf-8')
#发件人
msg['From'] = _format_addr('python lover : <%s>'%from_addr)
#收件人
msg['To'] = _format_addr('admin <%s>；'%to_addr)
#邮件标题
msg['Subject'] = Header('from smtp hello...','utf-8').encode()

server = smtplib.SMTP(smtp_server,25)
server.set_debuglevel(1)
server.login(from_addr,password)
server.sendmail(from_addr,[to_addr],msg.as_string())
server.quit()