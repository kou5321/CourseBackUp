# 本地Chrome浏览器设置方法

from selenium import  webdriver

import time



driver = webdriver.Chrome()

driver.get('https://xiaoke.kaikeba.com/example/X-Man/')

time.sleep(2)



teacher = driver.find_element_by_id('teacher')

teacher.send_keys('开课吧')

assistant = driver.find_element_by_name('assist')

assistant.send_keys('全都喜欢')

time.sleep(2)

button = driver.find_element_by_tag_name('button')

time.sleep(1)

button.click()

time.sleep(5)

driver.close()