# -*- coding: GB18030 -*-
"""
@auther:哑铃
@e-mail:2522348780@qq.com
@file:机器学习-PyCharm-市场分析.py
@time:2020/4/19 0019 21:31
"""
import requests
from bs4 import BeautifulSoup
import re
import numpy as np
import pandas as pd
import os
os.chdir('E:\C盘数据')
# url100='https://gouwu.sogou.com/shop?query=%C4%CC%D6%C6%C6%B7&isAbroad=0&host=sogou.com&rank=0&priceLowest=0&pid=sogou-navi-88f334ae12274afe&priceDown=0&display=grid&interV='
url100='https://gouwu.sogou.com/shop?query=%E4%B9%B3%E5%93%81&cq=on&classify=815&pid=sogou__free&host=sogou.com'
rqq = requests.get(url100)
soup = BeautifulSoup(rqq.content,'lxml')
a111=soup.select('#s_list_r_3 >span>a')
#s_list_r_3
a0=[str(i)[174:174+7] for i in a111]
a1=[str(i)[253:260] for i in a111]
b1=[re.findall('_.*_.*',a1[i]) for i in range(len(a1))]
# b2=[str(re.findall('[0-9]_.*',a1[i])) for i in range(len(a1))]
# b2=[str(b2)[] for i in range(len(a1))]
# b2=str(b2)
print(b1)
#sr_r_pic_809_1
#sResultList
N=int(input("请输入最大爬取页码:"))
j=int(input('请输入奶制品品牌:'))
str1=a0[j]
b=[]
c1=[]
c3=[]
for i in range(N):
    # url1='https://gouwu.sogou.com/shop?display=grid&query=%C4%CC%D6%C6%C6%B7&host=sogou.com&isAbroad=0&rank=0&pid=sogou-navi-88f334ae12274afe&priceDown=0&attr='+str(str1)+'&interV=&priceLowest=0&page='+str(i+1)+'&sourceid=sr_bpage&interV='
    url1='https://gouwu.sogou.com/shop?display=grid&classify=815&query=%C8%E9%C6%B7&host=sogou.com&isAbroad=0&rank=0&pid=sogou__free&priceDown=0&cq=on&attr='+str(str1)+'&interV=&priceLowest=0&page='+str(i+1)+'&sourceid=sr_bpage&interV='
         # 'https://gouwu.sogou.com/shop?display=grid&classify=815&query=%C8%E9%C6%B7&host=sogou.com&isAbroad=0&rank=0&pid=sogou__free&priceDown=0&cq=on&attr=1357224&interV=&priceLowest=0&page=4&sourceid=sr_bpage&interV='
    rqq = requests.get(url1)
    print(url1)
    soup = BeautifulSoup(rqq.content,'lxml')
    c2 = []
    for i in range(len(soup.select('#sResultList>div>h4'))):
        url='#sr_r_all_809_'+str(i)+'> div.item_price > span.item_price_sale'
        # time.sleep(0.0005)
        c2.append(str(soup.select(url)))
    c1.append([i.text for i in soup.select('#sResultList>div>h4')])
    c3.append([i.text for i in soup.select('#sResultList>div>div>em')])
    for i in range(len(c2)):
        if c2[i]!='':
            b1=c2[i][31:]
            b.append(re.sub(pattern='</span>]',repl='',string=b1))
        else:
            b.append('0')
a=np.array(c1).ravel()
b=np.array(b)
c=np.array(c3).ravel()
data=pd.DataFrame({'a':a,'b':b,'c':c})
data.to_excel('./data.xlsx',sheet_name='a')