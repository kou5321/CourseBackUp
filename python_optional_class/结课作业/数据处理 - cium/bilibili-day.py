import pandas as pd
import openpyxl
import matplotlib
import time
from matplotlib import font_manager
from matplotlib import pyplot as plt
df=pd.read_excel('D:\\solfware Python\\bilibili\\month.xls',sheet_name='Sheet1')
gp=df.groupby('播放量（万）')
#print(gp.head(10))
x=df['播放量（万）']
y=df['硬币']#改成硬币，点赞，收藏，弹幕量即可
plt.scatter(x,y,color='red',alpha=0.5)
plt.xlabel('播放量（万）')
plt.ylabel('硬币')
plt.title('播放量（万）与硬币量关系')
plt.show()
#time.sleep(100)