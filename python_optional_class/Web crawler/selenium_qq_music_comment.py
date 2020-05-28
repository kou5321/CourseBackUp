# 这段代码在本地执行

from selenium import webdriver #从selenium库中调用webdriver模块

import time



driver = webdriver.Chrome() # 设置引擎为Chrome，从本地打开一个Chrome浏览器

driver.get('https://y.qq.com/n/yqq/song/001qvvgF38HVc4.html') # 访问页面

time.sleep(2)



while True:

    try:

        clickformore = driver.find_element_by_class_name('js_get_more_hot')
        clickformore = driver.find_element_by_class_name('comment__show_all_link c_tx_thin js_get_more_hot')
        time.sleep(0.5)

        clickformore.click()

    except:

        print("不能再点击加载更多啦")

        break



comments = driver.find_element_by_class_name('js_hot_list').find_elements_by_class_name('js_cmt_li') # 使用class_name找到评论
# comments = driver.find_element_by_class_name('comment__list js_hot_list').find_elements_by_class_name('comment__list_item c_b_normal js_cmt_li') # 使用class_name找到评论

print(len(comments))



for i in range(len(comments)): # 循环

    comment = comments[i].find_element_by_tag_name('p') # 找到评论

    print ('评论'+str(i)+':'+comment.text + '\n-------------------------------------------------') # 打印评论



driver.close() # 关闭浏览器