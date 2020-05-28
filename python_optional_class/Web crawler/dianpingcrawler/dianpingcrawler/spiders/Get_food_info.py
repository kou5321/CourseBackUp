import scrapy
import bs4
from ..items import DianpingcrawlerItem


class Get_food_info(scrapy.Spider):
    name = 'GetFoodInfo'
    allowed_domains = ['http://www.dianping.com']
    start_urls = ['http://www.dianping.com/qingdao/ch10']

    def parse(self,response):
        bs = bs4.BeautifulSoup(response.text, 'html.parser')
        all_info = bs.find_all('li', class_="")
        for info in all_info:
            item = DianpingcrawlerItem()
            item['shopname'] =info.find_all()
