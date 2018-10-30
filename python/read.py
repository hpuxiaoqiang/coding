#-*- coding:utf-8 -*-
with open('/home/xiaoqiang/Desktop/python/diabetic_data.txt','r') as f:
    with open('/home/xiaoqiang/Desktop/python/new_part.txt', 'w') as nf:
        # print(f.read())
        #f.readlines()/home/xiaoqiang/Desktop/python/part.txt
        num = 0
        for line in f.readlines():
            # print(type(line))  #'str'
            line_list = line.strip().split('\t')  # 'str to list '
            # print(line_list)

            if line_list[11] != '?':
                print(line_list[11])
                num=num+1
                nf.write('  '.join(line_list)+'\n')
        print(num)