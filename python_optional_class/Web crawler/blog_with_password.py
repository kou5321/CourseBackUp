import requests
from bs4 import BeautifulSoup

post_url = 'https://xiaoke.kaikeba.com/example/wordpress/2019/11/07/%E4%BA%92%E8%81%94%E7%BD%91%E5%9C%88%E7%82%B8%E9%94%85%E5%95%A6%EF%BC%81%E6%9C%89%E4%BA%BA%E8%A6%81%E5%B8%AE%E4%BD%A0%E5%8A%A0%E8%96%AA%E5%95%A6%EF%BC%81/'

url_login = 'https://xiaoke.kaikeba.com/example/wordpress/wp-login.php?action=postpass'

headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 6.1; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/77.0.3865.120 Safari/537.36'}

session = requests.session()


def getContent():
    res = session.get(post_url, headers=headers)
    html_content = BeautifulSoup(res.text, 'html.parser')
    post_content = html_content.find('div', class_='entry-content')
    if (post_content is None):
        print('没有内容')
    else:
        print(post_content.text)


getContent()

data_login = {
    'post_password': 'xiaoke123',
    'Submit': '提交'
}
res = session.post(url_login, headers=headers, data=data_login)

print(res.status_code)

getContent()
