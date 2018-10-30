# -*- coding:utf-8 -*-
import hashlib,random
md5 = hashlib.md5()
md5.update('how to use md5 in python hashlib?'.encode('utf-8'))
print(md5.hexdigest())


# db = {
#     'michael': 'e10adc3949ba59abbe56e057f20f883e',
#     'bob': '878ef96e86145580c38c87f0410ad153',
#     'alice': '99b1c2188db85afee403b1536010c2c9'
# }
# def login(user, password):
#     md5_password = hashlib.md5()
#     md5_password.update(password.encode('utf-8'))
#     if md5_password.hexdigest() == db[user]:
#         print('welcome '+user+'!')
#     else:
#         print('password is wrong!')

def get_md5(password):
    # md5_password = hashlib.md5()
    return hashlib.md5(password.encode('utf-8')).hexdigest()
class User(object):
    def __init__(self,username,password):
        self.name = username
        self.salt = ''.join([chr(random.randint(48,122)) for i in range(20)])
        self.password = get_md5(password+self.salt)
db = {
    'michael': User('michael', '123456'),
    'bob': User('bob', 'abc999'),
    'alice': User('alice', 'alice2008')
}
def login(username, password):
    user = db[username]
    # print(user.name,':',user.password)
    if user.password == get_md5(password+user.salt):
        print('welcome ',user.name)
    else:
        print('Wrong!')


# 测试:
login('michael', '123456')
login('bob', 'abc999')
login('alice', 'alice2008')
login('michael', '1234567')
login('bob', '123456')
login('alice', 'Alice2008')
print('ok')