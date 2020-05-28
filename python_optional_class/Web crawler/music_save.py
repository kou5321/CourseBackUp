# from kkb_tools import open_file
import requests
import openpyxl

url = 'https://c.y.qq.com/soso/fcgi-bin/client_search_cp'
wb = openpyxl.Workbook()
# 创建工作薄
sheet = wb.active
# 获取工作薄的活动表
sheet.title = 'songs_mayday'
# 工作表重命名
column_name = ['歌曲名', '所属专辑', '播放时长', '播放链接']
sheet.append(column_name)
for x in range(0, 3):
    params = {
        'ct': '24',
        'qqmusic_ver': '1298',
        'new_json': '1',
        'remoteplace': 'sizer.yqq.song_next',
        'searchid': '64405487069162918',
        't': '0',
        'aggr': '1',
        'cr': '1',
        'catZhida': '1',
        'lossless': '0',
        'flag_qc': '0',
        'p': str(x + 1),
        'n': '20',
        'w': '五月天',
        'g_tk': '5381',
        'loginUin': '0',
        'hostUin': '0',
        'format': 'json',
        'inCharset': 'utf8',
        'outCharset': 'utf-8',
        'notice': '0',
        'platform': 'yqq.json',
        'needNewCode': '0'
    }
    # 将参数封装为字典
    res_music = requests.get(url, params=params)
    # 调用get方法，下载这个列表
    json_music = res_music.json()
    # 使用json()方法，将response对象，转为列表/字典
    list_music = json_music['data']['song']['list']
    # 一层一层地取字典，获取歌单列表
    for music in list_music:
        name = music['name']
        # 以name为键，查找歌曲名，把歌曲名赋值给name
        album = music['album']['name']
        # 查找专辑名，把专辑名赋给album
        time = music['interval']
        # 查找播放时长，把时长赋值给time
        link = 'https://y.qq.com/n/yqq/song/' + str(music['file']['media_mid']) + '.html\n\n'
        # 查找播放链接，把链接赋值给link
        sheet.append([name, album, time, link])
        # 把name、album、time和link写成列表，用append函数多行写入Excel

wb.save('mayday.xlsx')
wb.close()
# 最后保存并关闭这个Excel文件
# open_file('mayday.xlsx')
