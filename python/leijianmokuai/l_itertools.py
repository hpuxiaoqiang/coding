# -*- coding:utf-8 -*-
import itertools
def pi(N):
    # ' 计算pi的值 '
    # step 1: 创建一个奇数序列: 1, 3, 5, 7, 9, ...
    ls = itertools.count(1,2)
    # step 2: 取该序列的前N项: 1, 3, 5, 7, 9, ..., 2*N-1.
    ls_N = list(itertools.takewhile(lambda x : x<=2*N,ls))
    print(ls_N)
    # ls_N = ls[:N]
    # step 3: 添加正负符号并用4除: 4/1, -4/3, 4/5, -4/7, 4/9, ...
    for i in range(N):
        if(i&1):
            ls_N[i] = -4/ls_N[i]
        else:
            ls_N[i] = 4/ls_N[i]
    # step 4: 求和:
    sum_n = sum(ls_N)
    return sum_n
print(pi(1000))
