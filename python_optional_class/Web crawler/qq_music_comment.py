import requests
import requests

url = 'https://c.y.qq.com/base/fcgi-bin/fcg_global_comment_h5.fcg'

headers = {
    'user-agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/69.0.3497.92 Safari/537.36'}

for i in range(5):
    params = {
        'g_tk': '5381',
        'loginUin': '0',
        'hostUin': '0',
        'format': 'json',
        'inCharset': 'utf8',
        'outCharset': 'GB2312',
        'notice': '0',
        'platform': 'yqq.json',
        'needNewCode': '0',
        'cid': '205360772',
        'reqtype': '2',
        'biztype': '1',
        'topid': '102065756',
        'cmd': '6',
        'needmusiccrit': '0',
        'pagenum': str(i),
        'pagesize': '15',
        'lasthotcommentid': 'song_102065756_3202544866_44059185',
        'domain': 'qq.com',
        'ct': '24',
        'cv': '10101010'
    }

res_comment = requests.get(url, headers=headers, params=params)
json_comments = res_comment.json()
list_comments = json_comments['comment']['commentlist']
for comment in list_comments:
    print(comment['rootcommentcontent'])
print('----------------------')