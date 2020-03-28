#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include <malloc.h>

#define Len 20000
#define Up (Len * 3 / 4)

typedef char ElemType;
typedef struct node //定义双向链表
{
    ElemType data; //数据域
    struct node *next;
    struct node *front; //指针域
} List, *pList;         //结点类型，结点指针

// pList pHead = (pList)malloc(sizeof(List));
// pList pTail = (pList)malloc(sizeof(List));
//常量表达式中不允许函数调用

char ans[Len + 5];
int forprt = 0;

pList creat(char *a, int n)
{
    /* n为参数个数，*a为传入参数*/
    int i;
    pList pHead = (pList)malloc(sizeof(List));
    pList pTail = (pList)malloc(sizeof(List)); //创建头指针和尾指针

    pList pt = pHead; // pt指向头指针

    pTail->front = pHead;
    pTail->next = NULL;
    pHead->next = pTail;
    pHead->front = NULL;             //创建空的双向链表
    pHead->data = pTail->data = '-'; //赋值为'-',表示轨道上已没有珠子

    for (i = 0; i < n; i++)
    {
        pList pNew = (pList)malloc(sizeof(List));
        pNew->data = a[i];  // 先通过gets得到数组储存字符串，然后通过数组来传值
        pNew->front = pt; 
        pNew->next = pt->next;
        pt->next->front = pNew;
        pt->next = pNew;
        pt = pNew;  //移动pt指针
    }
    return pHead;
}

pList insert(int m, char ch, pList pHead)
{
    int i = -1; // i=-1.方便对位置零操作

    pList pt = pHead, pNew = (pList)malloc(sizeof(List));

    while (i++ < m)
        pt = pt->next; //找到带插入位置

    pNew->data = ch;
    pNew->next = pt;
    pNew->front = pt->front;
    pt->front->next = pNew;
    pt->front = pNew; //注意是插在找到位置的前面

    return pHead;
}

pList find_tail(pList pHead)
{
    pList pt = pHead->next;
    //while(!(pt->data == '-')) pt = pt ->next;
    while (pt->next != NULL)
        pt = pt->next;   //这两种方法都可以找到pTail
    return pt;
}

pList del(int m, pList pHead)
{
    pList pTail, point_tmp;
    pTail = find_tail(pHead);
    //获得ptail
    pList p1 = NULL, p2 = NULL, p3 = NULL, p4 = NULL, pt = pHead; //空指针最好赋值 NULL
    pList begin = pHead, end = pTail; 
    int boo = 1; //gcc编译器不支持bool类型，所以用int表示逻辑
    int repeat, i = -1;

    // find position
    while (i++ < m - 2)
        pt = pt->next; // 找到插入位置前两个指针

    //init for 'begin' and 'end'
    begin = pt;
    end = pt;
    i = 0;
    while (i++ < 4 && end->next != pTail)
        end = end->next; //找到插入位置后两个指针

    while (boo && pt != pTail)
    {
        boo = 0; //判断有没有发生消除
        repeat = 1; //计数重复的个数
        while (pt != end) //pt在begin位置
        {
            pt = pt->next;

            if (pt->front->data == pt->data) //pt后移，如果data相同，就计数加一
                repeat++;
            else
                repeat = 1;

            if (repeat == 3)
            {
                boo = 1;
                if (pt->data == pt->next->data) //已经满足消除条件了，再看看能不能继续满足
                {
                    repeat++;
                    pt = pt->next;
                }

                if (repeat == 3)
                {
                    p3 = pt;
                    p2 = p3->front;
                    p1 = p2->front;
                    p1->front->next = p3->next;
                    p3->next->front = p1->front;
                    pt = pt->next; //消除这三个，将pt后移
                    free(p1);
                    free(p2);
                    free(p3);
                }
                else
                {
                    p4 = pt;
                    p3 = p4->front;
                    p2 = p3->front;
                    p1 = p2->front;
                    p1->front->next = p4->next;
                    p4->next->front = p1->front;
                    pt = pt->next; //消除这4个，将pt后移
                    free(p1);
                    free(p2);
                    free(p3);
                    free(p4);
                }

                break;
            }
        }

        if (boo && pt != pTail)
        {
            begin = pt;
            i = 0;
            while (i++ < 2 && begin->front != pHead)
                begin = begin->front;
            end = pt;
            i = 0;
            if (i++ < 1 && end->next != pTail)
                end = end->next;
            pt = begin; //将pt的begin和end指针归位
        }
    }
    return pHead;
}

pList show(int boo, pList pHead) //将双向链表的值存到数组便于输出
{

    pList pt = pHead->next;
    pList pTail = find_tail(pHead);

    if (pt == pTail)
        ans[forprt++] = '-'; //没有数
    else
    {
        while (pt->next != NULL)
        {
            ans[forprt++] = pt->data; //扩容并存data
            pt = pt->next;  //pt后移
        }
    }

    ans[forprt++] = '\n'; //输出需要有换行

    if (forprt >= Up || boo) //如果到尽头了
    {
        ans[forprt] = '\0'; //数组一定要以 \0 结尾
        printf("%s", ans); //输出
        forprt = 0;
    }
    return pHead; //其实不需要返回了
}

int main(void)
{
    char a[10005];
    int n, k;
    pList pHead = NULL;

    //printf("请输入初始队列\n");
    gets(a); // 初始的珠子序列
    //printf("请输入操作数");
    scanf("%d", &n); // 共有n次操作

    pHead = creat(a, strlen(a)); //创建对应初始的珠子序列的双向链表

    for (k = 0; k < n; k++)
    {
        int m;
        char ch;

        scanf("%d ", &m); //新的珠子位序

        ch = getchar(); // 插入珠子颜色

        // insert ch
        insert(m, ch, pHead);

        // delete all 3-same block, making it the right string
        del(m, pHead);

        // print the string
        show(k == n - 1 ? 1 : 0, pHead);
    }

    return 0;
}