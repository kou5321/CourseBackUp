import pandas as pd
import matplotlib.pyplot as plt
from wordcloud import WordCloud
data=pd.read_csv("./bilibili.csv")
string=""
#将分类标签转为一个长的字符串
for i in list(data["tags"]):
    for j in (str(i).split(" ")):
        if j!="nan":
            string+=j
            string+=" "
wordcloud = WordCloud(font_path='/usr/share/fonts/wenquanyi/wqy-zenhei/wqy-zenhei.ttc').generate(string)
#生成词云
plt.imshow(wordcloud, interpolation='bilinear')
plt.axis("off")
plt.savefig("./tags.jpg")
