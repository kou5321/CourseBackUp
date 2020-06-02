import pandas as pd
import matplotlib.pyplot as plt
import jieba
from wordcloud import WordCloud
data=pd.read_csv("./bilibili.csv")
string=""
#将分词后的标题转化为长字符串
for i in list(data["title"]):
    for j in (str(i).split(" ")):
        seg_list = jieba.cut(j, cut_all=False)
        #用jieba库分词
        for k in seg_list:
            string+=k
            string+=" "
wordcloud = WordCloud(font_path='/usr/share/fonts/wenquanyi/wqy-zenhei/wqy-zenhei.ttc').generate(string)
#生成词云
plt.imshow(wordcloud, interpolation='bilinear')
plt.axis("off")
plt.savefig("./title.jpg")
