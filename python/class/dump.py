# -*- coding:utf-8  -*-
import pickle
d = dict(name = 'bob',age=20,score = 90)
pickle.dumps(d)
with open('dump.txt','wb') as f:
    pickle.dump(d,f)
    f.close()
with open('dump.txt','r') as rf:
    d1 = pickle.load(rf)
    print(d1)
    rf.close()