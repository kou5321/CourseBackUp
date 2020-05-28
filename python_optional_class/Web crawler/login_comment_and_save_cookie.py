import requests

import json

session = requests.session()

headers = {

    'User-Agent':'Mozilla/5.0 (Windows NT 6.1; Win64; x64)AppleWebKit/537.36 (KHTML, like Gecko) Chrome/77.0.3865.120 Safari/537.36'

}



def cookie_read(): # cookie读取。

    cookie_txt = open('cookie_kaikeba.txt', 'r')

    cookie_dict = json.loads(cookie_txt.read())

    cookie = requests.utils.cookiejar_from_dict(cookie_dict)

    return (cookie)



def sign_in():

    url_login = 'https://xiaoke.kaikeba.com/example/wordpress/wp-login.php'

    data_login = {'log': input('请输入你的账号'),

            'pwd': input('请输入你的密码'),

            'wp-submit': '登录',

            'redirect_to': 'https://xiaoke.kaikeba.com/example/wordpress/2019/10/17/%e5%bc%80%e8%af%be%e5%90%a7%e6%97%a0%e6%95%8c%e5%a5%bd%e5%90%83%e7%9a%84%e9%a3%9f%e5%a0%82%e4%b8%80%e5%91%a8%e8%8f%9c%e8%b0%b1/',

            'testcookie': '1'}

    session.post(url_login, headers=headers, data=data_login)

    # cookie存储。

    cookie_dict = requests.utils.dict_from_cookiejar(session.cookies)

    cookie_str = json.dumps(cookie_dict)

    f = open('cookie_kaikeba.txt', 'w')

    f.write(cookie_str)

    f.close()



def write_message(): #发表评论。

    url_comment = 'https://xiaoke.kaikeba.com/example/wordpress/wp-comments-post.php'

    data_comment = {

        'comment': input('请输入你要发表的评论：'),

        'submit': '发表评论',

        'comment_post_ID': '35',

        'comment_parent': '0'

    }

    return (session.post(url_comment, headers=headers, data=data_comment))



try:

    session.cookies = cookie_read()

except FileNotFoundError:

    sign_in()

    session.cookies = cookie_read()



num = write_message()

if num.status_code == 200:

    print('成功啦！')

else:

    sign_in()

    session.cookies = cookie_read()

    num = write_message()