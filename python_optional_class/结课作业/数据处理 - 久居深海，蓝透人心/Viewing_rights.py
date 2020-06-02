import pandas as pd
import matplotlib.pyplot as plt
data=pd.read_csv("./bilibili.csv")
is_vip=data.loc[:,'badge'].value_counts()
labels=["会员专享","会员抢先","限时免费","付费观看"]
plt.pie(is_vip,autopct='%.1f%%',labels=labels)
plt.title("观看权限")
plt.savefig("Viewing_rights.jpg")
