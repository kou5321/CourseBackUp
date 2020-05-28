import requests
import csv
#引用csv。
csv_file=open('articles.csv','w',newline='',encoding='gbk')
#调用open()函数打开csv文件，传入参数：文件名“articles.csv”、写入模式“w”、newline=''。
writer = csv.writer(csv_file)
# 用csv.writer()函数创建一个writer对象。

headers={'user-agent':'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/77.0.3865.90 Safari/537.36'}
url='https://www.zhihu.com/api/v4/members/lisanshui1230/articles'
offset=0
#设置offset的起始值为0
while True:
    params={
        'include':'data[*].comment_count,suggest_edit,is_normal,thumbnail_extra_info,thumbnail,can_comment,comment_permission,admin_closed_comment,content,voteup_count,created,updated,upvoted_followees,voting,review_info,is_labeled,label_info;data[*].author.badge[?(type=best_answerer)].topics',
        'offset':str(offset),
        'limit':'20',
        'sort_by':'created',
        }
    #封装参数
    res=requests.get(url,headers=headers,params=params)
    #发送请求，并把响应内容赋值到变量res里面
    articles=res.json()
    data=articles['data']
    #定位数据
    for i in data:
        article_info=[i['title'],i['url'],i['excerpt']]
        #把目标数据封装成一个列表
        print(article_info)
        #看看每行写入的内容
        writer.writerow(article_info)
        #调用writerow()方法，把列表article_info的内容写入
    offset=offset+20
    #在while循环内部，offset的值每次增加20
    if offset >= 60:
        break
csv_file.close()
#写入完成后，关闭文件就大功告成