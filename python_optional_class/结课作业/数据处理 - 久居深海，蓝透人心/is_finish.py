import pandas as pd
import matplotlib.pyplot as plt
data=pd.read_csv("./bilibili.csv")
is_finish=data.loc[:,'is_finish'].value_counts()
labels=["yes","no"]
plt.pie(is_finish,autopct='%.1f%%',labels=labels)
plt.title("is_finish")
plt.savefig("is_finish.jpg")
