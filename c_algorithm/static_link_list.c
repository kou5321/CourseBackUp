#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100 //静态链表大小
typedef int Elemtype;

typedef struct Node
{ //静态链表结点
    Elemtype data;
    int next; //注意指针域是数字
} Snode;

typedef struct
{ //静态链表
    Snode Nodes[MaxSize];
    int newptr; //当前可分配空间首地址
} SLinkList;

void InitList(SLinkList *SL) //j静态链表中指针表示下一元素在数组中的地址，如果更改地址要用指针，查找不就不用了
{
    int i;
    (*SL).Nodes[0].next = 1; //当前可分配空间从 1 开始
                             //建立带表头结点的空链表
    for (i = 1; i < MaxSize - 1; i++)
    {
        (*SL).Nodes[i].next = i + 1;       //构成空闲链接表
        (*SL).Nodes[MaxSize - 1].next = 0; //链表收尾
    }
}

// int main(int argc, char const *argv[])
// {
//     SLinkList l;
//     InitList(&l);
//     return 0;
// }

int Find(SLinkList Sl, Elemtype x)
{
    int p = Sl.Nodes[0].next; //指针 p 指向链表第一个结点，注意这里的“指针”是整型
    while (p != -1)
    { //逐个查找有给定值的结点
        if (Sl.Nodes[p].data != x)
        {
            p = Sl.Nodes[p].next;
        }
        else
            break;
    }
    return p;
}

int Locate(SLinkList Sl, int i)
{
    int j, p;
    if (i < 0)
        return -1; // 参数不合理
    j = 1;
    p = Sl.Nodes[0].next;
    while (p != -1 && j <= i - 1)
    { //循环查找第i 号结点
        p = Sl.Nodes[p].next;
        j++;
    }
    if (i == 0)
        return 0;
    return p;
}

int Insert(SLinkList *Sl, int i, Elemtype x) 
{
    int p, q;
    p = Locate(*Sl, i);
    if(p == -1) return 0; // 找不到结点
    q = (*Sl).newptr;  //在第一个可分配空间分配结点 
    (*Sl).newptr = (*Sl).Nodes[(*Sl).newptr].next; //newptr后移
    (*Sl).Nodes[q].data = x;
    (*Sl).Nodes[q].next = (*Sl).Nodes[p].next;
    (*Sl).Nodes[p].next = q; //不是(*Sl).Nodes[q]    注意静态链表是一个链表
    return 1;
}

int Remove(SLinkList *Sl, int i){
    int p = Locate(*Sl, i-1);     //第i-1号结点
    if(p==-1) return 0;           //找不到结点
    int q = (*Sl).Nodes[p].next;  //第 i 号结点，删除要两个结点的
    (*Sl).Nodes[p].next = (*Sl).Nodes[q].next;
    (*Sl).Nodes[q].next = (*Sl).newptr;
    (*Sl).newptr = q;
    return 1;
}

