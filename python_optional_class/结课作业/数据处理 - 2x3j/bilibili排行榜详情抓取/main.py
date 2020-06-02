import requests
from bs4 import BeautifulSoup
import re
import xlwt
import time
import random
import video_dict #自己编写的获取点赞，硬币，收藏的脚本

#爬取内容
def getHTMLText(url):
    try:
        kv = {'user-agent':'Mozilla/5.0'}
        r = requests.get(url,headers=kv) #模拟访问者是Mozilla5.0
        r.raise_for_status()
        r.encoding = 'utf-8-sig'
        return r.text
    except:
        print("无效链接!")

#解析内容
def getList(title1,BV,counts,view, html):
    soup = BeautifulSoup(html,'html.parser')
    ul = soup.find("ul", {"class": "rank-list"} )
    aa = 1
    #遍历所有li
    for li in ul.children:
        dev = li.find('div', {"class": "info"})
        #视频标题
        title = dev.find_all('a',{"class": "title"} )
        title1.append(title[0].string)
        #BV
        bv = str(title[0]['href'])
        bv = bv[-12:-1] + bv[-1]
        BV.append(bv)
        #播放量#评论数
        detail = dev.find('div',{"class": "detail"})
        span = detail.find_all('span',{"class": "data-box"} )
        #播放量
        a1 = re.search(r'([1-9]\d*\.?\d*)|(0\.\d*[1-9])',str(span[0]),flags=0)
        if a1:
            counts.append(eval(a1.group(0)))
        #评论数
        a2 = re.search(r'([1-9]\d*\.?\d*)|(0\.\d*[1-9])',str(span[1]),flags=0)
        if a2:
            a22 = eval(a2.group(0))
            if a22<100:
                a22 = a22*10000
            view.append(a22)
        time.sleep(random.random())
        print(f'\r正在抓取第{aa}条',end='')
        aa += 1

    title1 = title1[0:1000]
    counts = counts[0:1000]
    view = view[0:1000]
    BV = BV[0:1000]

#打印
def printList(title1,BV,counts,view, html):
    workbook = xlwt.Workbook(encoding = 'utf-8')
    worksheet = workbook.add_sheet('Sheet1')
    first_col=worksheet.col(0)
    first_col.width=700*20
    first_col1=worksheet.col(1)
    first_col1.width=200*20
    value = ['视频名称','BV号','播放量（万）','弹幕量','点赞','硬币','收藏']
    a = 0
    for i in value:
        worksheet.write(0,a, label = i)
        a += 1
    b = 1
    for i in title1:
        worksheet.write(b,0, label = i)
        b += 1

    c = 1
    for i in counts:
        worksheet.write(c,2, label = i)
        c += 1

    d = 1
    for i in view:
        worksheet.write(d,3, label = i)
        d += 1

    e = 1
    for i in BV:
        worksheet.write(e,1, label = i)
        e += 1

    f = 1
    for i in BV:
        worksheet.write(f,4, label = video_dict.like(i))
        worksheet.write(f,5, label = video_dict.coin(i))
        worksheet.write(f,6, label = video_dict.favorite(i))
        f += 1

    workbook.save('哔哩哔哩排行榜分析.xls')

#主函数
def main():
    print('1：日榜；2：3日榜；3：周榜；4：月榜')
    a = eval(input('请选择爬取的榜单：'))
    if a == 1:
        url = "https://www.bilibili.com/ranking/all/0/0/1"
    elif a == 2:
        url = "https://www.bilibili.com/ranking/all/0/0/3"
    elif a == 3:
        url = "https://www.bilibili.com/ranking/all/0/0/7"
    elif a == 4:
        url = "https://www.bilibili.com/ranking/all/0/0/30"

    print('正在爬取......')
    title1 = []    #视频标题
    counts = []    #播放量
    view = []      #弹幕量
    BV = []        #BV号
    like = []      #点赞
    coin = []      #硬币
    favorite = []  #收藏
    html = getHTMLText(url)
    getList(title1,BV,counts,view,html)
    print('正在进行信息汇总......')
    printList(title1,BV,counts,view,html)
    print('已成功保存为excel.')

main()
