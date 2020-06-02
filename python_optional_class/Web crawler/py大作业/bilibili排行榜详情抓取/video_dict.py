import requests
import json
import csv
import pandas as pd
alphabet = 'fZodR9XQDSUm21yCkr6zBqiveYah8bt4xsWpHnJE7jL5VG3guMTKNPAwcF'
def dec(x):#BV号转换成AV号
    r = 0
    for i, v in enumerate([11, 10, 3, 8, 4, 6]):
        r += alphabet.find(x[v]) * 58**i
    return (r - 0x2_0840_07c0) ^ 0x0a93_b324

#获取点赞数
def vedio(bid):
    aid = dec(bid)
    url = r'https://api.bilibili.com/x/web-interface/archive/stat?aid=' +str(aid)
        # 携带cookie进行访问
    headers = {
                'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/77.0.3865.120 Safari/537.36'
                }
     # 获取url
    response = requests.get(url , timeout=30,headers = headers)
    text = response.text
    jsonobj = json.loads(text)

    #从Json对象获取视频基本信息并转入词典中
    video_dict = {'aid':jsonobj['data']['aid'],
                 'bvid':jsonobj['data']['bvid'],
                 'view':jsonobj['data']['view'],
                 'danmuku_num':jsonobj['data']['danmaku'],
                 'reply_num':jsonobj['data']['reply'],
                 'favorite_num':jsonobj['data']['favorite'],
                 'coin_num':jsonobj['data']['coin'],
                 'share_num':jsonobj['data']['share'],
                 'like_num':jsonobj['data']['like']
                 }
    return video_dict
#获取点赞数
def like(bid):
    dict = vedio(bid)
    return dict['like_num']
#获取硬币数
def coin(bid):
    dict = vedio(bid)
    return dict['coin_num']
#获取收藏数
def favorite(bid):
    dict = vedio(bid)
    return dict['favorite_num']
