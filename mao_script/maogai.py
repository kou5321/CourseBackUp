# coding:utf-8
import re


def find_ans(question, ans, found_ans, question_num):
    ans = open(ans, encoding='utf-8')
    txt = ans.readlines()
    for i in range(len(txt)):
        try:
            for ch in '!\"\'#$%&()*+,-./:;<=>?@[\\]^_‘{|}~，‘’“”：；。？、！·《》（）【】\n \t':
                txt[i] = txt[i].replace(ch, "")
            question = ''.join(question.split('\n'))
            if txt[i].__contains__(question):
                if txt[i].__contains__('参考答案'):
                    print(txt[i].strip())
                    found_ans[question_num-1] = 1
                elif txt[i+1].__contains__('参考答案'):
                    print(txt[i+1].strip())
                    found_ans[question_num-1] = 1
                elif txt[i+2].__contains__('参考答案'):
                    print(txt[i+2])
                    found_ans[question_num-1] = 1
        except:
            continue
    ans.close()

f = open('maogai.txt', encoding='utf-8')
questions = []
for line in f:
    if line.__contains__('id="question_'):
        p = re.compile(r'[\u4e00-\u9fa5]')
        res = re.findall(p, line)
        questions.append(''.join(res))
# for question in questions:
#    print(question)
i = 0
found_answer = [0 for j in range(30)]
for question in questions:
    i += 1
    print(i)
    find_ans(question, 'answer.txt', found_answer, i)
for k, ans in enumerate(found_answer):
    if not ans:
        print('未找到答案的题：', k+1)
