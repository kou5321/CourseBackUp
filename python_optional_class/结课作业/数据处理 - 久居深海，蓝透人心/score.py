import pandas as pd
import matplotlib.pyplot as plt
data=pd.read_csv("./bilibili.csv")
score=data.loc[:,'score'].value_counts()
score.plot.bar()
plt.savefig("./score.jpg")
