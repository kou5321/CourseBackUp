from selenium import webdriver
import time

driver = webdriver.Chrome()
driver.get('https://xiaoke.kaikeba.com/example/wordpress/')
time.sleep(2)

title = driver.find_element_by_class_name('entry-title').find_element_by_tag_name('a')
title.click()  #跳转进入文章详情页
time.sleep(1)

link_login = driver.find_element_by_class_name('must-log-in').find_element_by_tag_name('a')
link_login.click()

########登录#########
#输入用户名
login_user = driver.find_element_by_id("user_login")
user = input("请输入用户名：")
login_user.send_keys(user)
#输入密码
login_password = driver.find_element_by_id("user_pass")
pwd = input("请输入密码：")
login_password.send_keys(pwd)
#点击登录
login_confirm = driver.find_element_by_id("wp-submit")
login_confirm.click()

######进行评论######
#输入评论内容
comment_area = driver.find_element_by_id("comment")
comment = input("请输入你想要评论的内容:")
comment_area.send_keys(comment)
#提交评论
comment_submit = driver.find_element_by_id("submit")
comment_submit.click()
time.sleep(3)

driver.close()
