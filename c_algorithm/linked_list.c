#include <stdio.h>
#include <stdlib.h>

#define error 0
#define right 1
typedef int Elemtype;
typedef struct node
{                      //链表结点
    Elemtype data;     //结点数据域
    struct node *next; //结点的指针域
} Listnode;
typedef Listnode *Linklist;
Linklist first; //链表头指针first

int Insert(Linklist *first, int x, int i) //注意c是没有引用的
{
    //在链表第i 个结点前插入新元素 x
    Listnode *p = first;
    int k = 0;
    while (p != NULL && k < i - 1)
    {
        p = p->next;
        k++;
    } //找到第i-1个结点
    if (p == NULL && first != NULL)
    {
        printf("无效的插入位置!\n");
        return error;
    }
    Listnode *newnode = (Listnode *)malloc(sizeof(Listnode));
    newnode->data = x;
    if (first == NULL || i == 1)
    { //插入空表或非空表第一个 结点之前
        newnode->next = first;
        first = newnode;
    }
    else
    { //插在表中间或末尾
        newnode->next = p->next;
        p->next = newnode;
    }
    return right;
}

int Delete(Linklist *first, int i)
{
    Linklist *p, *q;
    if (i == 0)
    { //删除表中第1 个结点
        q = first;
        first = first->next;
    }
    else
    {
        p = first;
        int k = 0;
        while (p != NULL && k < i - 1)
        {
            p = p->next;
            k++; //找第i-1个结点
        }
        if (p == NULL || p->next == NULL)
        { //找不到第 i-1个结
            printf("无效的删除结点\n");
            return error;
        }
        else
        { //删除中间结点或尾结点元素
            q = p->next;
            p->next = q->next;
        }
        // if(q==last) last=p; //删除表尾结点
        k = q->data;
        free(q); //取出被删结点数据并释 放q
        return k;
    }
}

/*带表头结点的单链表*/
int Insert2(Linklist first, Elemtype x, int i)
{
    Listnode *p;
    p = Locate(first, i - 1);
    if (p != NULL)
        return 0; //参数i值不合理返回0
    Listnode *newnode = (Listnode *)malloc(sizeof(Listnode));
    newnode->data = x;
    newnode->next = p->next;
    p->next = newnode;
    return 1;
}

int Delete2(Linklist first, int i)
{
    Linklist p, q;
    p = Locate(first, i - 1); //寻找第i-1个结点
    if (p == NULL || p->next == NULL)
        return 0;
    q = p->next;
    p->next = q->next;
    free(q);
    return 1;
}

int Length2(Linklist first)
{
    Linklist p;
    p = first->next; //指针p 指示第一个结点
    int count = 0;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}

void makeEmpty()
{
    //删去链表中除表头结点外的所有其它结点
    Linklist q;
    while (first->next != NULL)
    { //当链不空时，循环逐个删去所有结点
        q = first->next;
        first->next = q->next;
        free(q);
    }
}

Linklist Find(Linklist first, Elemtype value)
{
    Listnode *p;
    p = first->next; //指针 p 指示第一个结点
    while (p != NULL && p->data != value)
        p = p->next;
    return p;
}

Linklist Locate(Linklist first, int i)
{
    //返回表中第i 个元素的地址
    Linklist *p;
    int k;
    if (i < 0)
        return NULL;
    p = first;
    k = 0;
    while (p != NULL && k < i)
    {
        p = p->next;
        k++; //找第 i 个结点
    }
    if (k == i)
        return p; //返回第i 个结点的地址
    else
        return NULL;
}

/*头插法建立单链表*/
void createListF(Linklist *first, Elemtype a[], int n)
{ //形式参数first为指针参数，（指向指针的指针）
    int i;
    Linklist q;
    *first = (Linklist)malloc(sizeof(Listnode)); //建立表头结点
    (*first)->next = NULL;
    for (i = n - 1; i >= 0; i--)
    { //注意从n-1开始
        q = (Linklist)malloc(sizeof(Listnode));
        q->data = a[i];
        q->next = (*first)->next;
        (*first)->next = q;
    }
}

Linklist createListR()
{ //尾插法建立单链表,函数值返回头结点指针
    char ch;
    Linklist first = (Linklist)malloc(sizeof(Listnode)); //建立表头结点
    Listnode *q, *r = first;
    while ((ch = getchar() != '\n'))
    {
        q = (Linklist)malloc(sizeof(Listnode));
        q->data = ch;
        r->next = q;
        r = q; //插入到表末端
    }
}

/*
设计一个算法，在带头结点的单链表L中删除所有值为x的结点并释放空间，假设这样的结点不是唯一的。
*/

typedef struct Node
{
    int data;
    struct Node *next;
} Listnode, *Linklist;

void createListR()
{
    Linklist first = (Linklist)malloc(sizeof(Listnode));
    Linklist p, q = first;
    char ch;
    while ((ch = getchar()) != NULL)
    {
        p = (Linklist)malloc(sizeof(Listnode));
        q->data = ch;
        q->next = p;
        q = p;
    }
    q->next = NULL;
    return first; //函数值返回头结点指针
}

void Del(Linklist L, Elemtype x)
{
    Linklist p = L->next, *pre = L, *q;
    while (p != NULL)
    {
        if (p->data == x)
        {
            q = p;
            p = p->next;
            pre->next = p;
            free(q);
        }
        else
        {
            pre = p;
            p = p->next;
        }
    }
}

/*练习2：设计一个算法，在带头结点的单链表L中 删除一个最小值结点，假设其唯一。*/
void delMinNode(Linklist L)
{
    Linklist pre = L, p = pre->next, *minp = p, *minpre = pre;
    while (p != NULL)
    { //查找最小值节点 *minp及其前趋节点 *minpre
        if (p->data < minp->data)
        {
            minp = p;
            minpre = pre;
        }
        pre = p;
        p = p->next; //p、pre同步后移一个节点
    }
    minpre->next = minp->next;
    free(minp);
}

/*设C={a1,b1,a2,b2,…,an,bn}为一线性表，采 用带头结点的hc单链表存放，设计一个就地算法， 将其拆分为两个单链表ha和hb*/
void Split(Linklist hc, Linklist *ha, Linklist *hb)
{
    Linklist p = hc->next, ra, rb;
    *ha = hc;
    ra = hc;
    *hb = (Linklist)malloc(sizeof(Listnode));
    rb = *hb;
    while (p != NULL)
    {
        if (p != NULL)
        {
            ra->next = p;
            ra = p;
            p = p->next;
        }
    }
    ra->next = rb->next = NULL; // 没看懂？？？
}

// 搜索链表最后一个结点并打印其数值
void search(Linklist f)
{
    if (f->next == NULL)
        printf("%d\n", f->data);
    else
    {
        search(f->next);
    }
}

// 在链表中寻找等于给定值的结点,并打印其数值
void Search(Listnode *f, Elemtype x)
{
    if (f != NULL)
        if (f->data == x)
            printf("%d\n", f->data);
        else
            Search(f->next, x);
}