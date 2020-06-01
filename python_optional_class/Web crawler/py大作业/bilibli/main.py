import pandas as pd
import matplotlib.pyplot as plt
from wordcloud import WordCloud
data=pd.read_csv("./bilibili.csv")
index_show=data.loc[:,'index_show'].value_counts()
index_show.head(15).plot.bar()
plt.xlabel("集数")
plt.ylabel("数量")
plt.title("集数条形图")
plt.savefig("index_show.jpg")
