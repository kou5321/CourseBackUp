#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int Elemtype;
typedef struct node
{                      //链表结点
    Elemtype data;     //结点数据域
    struct node *next; //结点指针域
} Listnode, *Linklist; //节点类型，节点指针

typedef struct dnode
{
    Elemtype data;              //结点数据域
    struct dnode *prior, *next; //结点指针域
} DblNode, *DblList;            //节点类型，节点指针

DblList createDblList(); //此处用了双向循环链表
DblList mergeDblList(DblList, DblList);
void outputDblList(DblList); //空链表将输出NULL

void main()
{
    DblList L1, L2, L;
    printf("please input sequence1, end with -1:\t"); //本来想换行结尾，但是这样输入就是char了
    L1 = createDblList();
    printf("please input sequence2, end with -1:\t");
    L2 = createDblList();
    L = mergeDblList(L1, L2);
    printf("the result is:");
    outputDblList(L);
}

DblList createDblList() //建立双向循环链表
{
    DblList head, pa, pb;
    int x = 0;
    scanf("%d", &x);
    if (x == -1)
        exit(1);
    head = (DblList)malloc(sizeof(DblNode));
    head->prior = head->next = head; //表头结点的链指针指向自己
    pa = head;
    while (x != -1)
    {
        pb = (DblList)malloc(sizeof(DblNode));
        pb->data = x;
        pb->prior = pa;
        pb->next = pa->next;
        pa->next->prior = pb;
        pa->next = pb;
        pa = pb;
        scanf("%d", &x);
    }
    return head; //返回头指针
}

DblList mergeDblList(DblList La, DblList Lb)
{
    DblList Lc, pa, pb, pc;
    // Lc = (DblList)malloc(sizeof(DblNode));
    Lc = La; //c链表的头结点，直接在a链表头结点就地操作，降低空间复杂度
    pc = La; // pc是用于插入的前一个结点
    pa = La->next;
    pb = Lb->next;               //pa，pb是待插入的结点
    while (pa != La && pb != Lb) //while (pa!=NULL && pb!=NULL) //La,Lb链表不为空
    {
        if (pa->data < pb->data) //为了实现非降序排列需要进行分类讨论
        {
            pa->prior = pc;
            pa->next = pc->next;
            pc->next = pa;
            pc->next->prior = pa; //插入结点，并加入连接
            pc = pa;
            pa = pa->next; //pc后移，pa后移
            // DblList ptr = pa->next;
            // pa->prior = pc;
            // pa->next = pc->next;
            // pc->next->prior = pa;
            // pc->next = pa;
            // pc = pa;
            // pa = ptr;
        }
        if (pa->data > pb->data)
        {
            // DblList ptr = pb->next;
            // pb->prior = pc;
            // pb->next = pc->next;
            // pc->next->prior = pb;
            // pc->next = pb;
            // pc = pb;
            // pb = ptr;
            pb->prior = pc;
            pb->next = pc->next;
            pc->next = pb;
            pc->next->prior = pb;
            pc = pb;
            pb = pb->next; //同上
        }
        else //相等的话，就重复上述两个操作
        {
            pa->prior = pc;
            pa->next = pc->next;
            pc->next = pa;
            pc->next->prior = pa;
            pc = pa;
            pa = pa->next;
            
            pb->prior = pc;
            pb->next = pc->next;
            pc->next = pb;
            pc->next->prior = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    if (pa != La)
    {
        while (pa != La)
        {
            pa->prior = pc;
            pa->next = pc->next;
            pc->next = pa;
            pc->next->prior = pa;
            pc = pa;
            pa = pa->next; //重复对a操作
        }
    }
    if (pb != Lb)
    {
        while (pb != Lb)
        {
            pb->prior = pc;
            pb->next = pc->next;
            pc->next = pb;
            pc->next->prior = pb;
            pc = pb;
            pb = pb->next; //重复对b操作
        }
    }
    return Lc; //返回头结点
}

void outputDblList(DblList s)
{
    DblList head = s;
    s = s->next;
    if (s == head)
    {
        printf("NULL"); //空链表输出NULL
        return;         //直接结束，不执行下面代码
    }
    while (s != head)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
    return;
}