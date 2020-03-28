#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType;
typedef struct node
{                      //链表结点
    ElemType data;     //结点数据域
    struct node *next, *prior; //结点指针域
} Listnode, *Linklist; //节点类型，节点指针

Linklist create_list(); //此处用了单链表
Linklist merge_list(Linklist, Linklist);
void output_list(Linklist); //空链表将输出NULL

void main()
{
    Linklist L1, L2, L;
    printf("please input sequence1, end with -1:\t"); //本来想换行结尾，但是这样输入就是char了
    L1 = create_list();
    printf("please input sequence2, end with -1:\t");
    L2 = create_list();
    L = merge_list(L1, L2);
    printf("the result is:");
    output_list(L);
}

Linklist create_list() //创建链表并赋值
{
    int x;
    Linklist head, pa, pb; //头结点和两个指针,pb用来开辟空间，pa用来连接pb
    scanf("%d", &x);
    if(x==1) exit(1); //如果第一个输入为-1，异常退出
    head = (Linklist)malloc(sizeof(Listnode)); //定义头结点
    pa = head;
    while (x != -1)
    {
        pb = (Linklist)malloc(sizeof(Listnode));
        pb->data = x;
        pa->next = pb;
        pb->prior = pa;
        pa = pb;
        scanf("%d", &x);
    }
    pb->next = NULL;
    return head; //返回头结点
}

Linklist merge_list(Linklist La, Linklist Lb)
{
    Linklist Lc, pa, pb, pc;
    Lc = La; //c链表的头结点，直接在a链表就地操作，降低空间复杂度
    pc = La;
    pa = La->next;
    pb = Lb->next;   //pa,pb,pc为指针
    while (pa && pb) //while (pa!=NULL && pb!=NULL) //La,Lb链表不为空
    {
        if (pa->data < pb->data) //为了实现非降序排列需要进行分类讨论
        {
            pc->next = pa;
            pa->prior = pc;
            pc = pa;
            pa = pa->next;
        }
        if (pa->data > pb->data)
        {
            pc->next = pb;
            pb->prior = pc;
            pc = pb;
            pb = pb->next;
        }
        else //相等的话，就重复上述两个操作
        {
            pc->next = pa;
            pa->prior = pc;
            pc = pa;
            pa = pa->next;

            pc->next = pb;
            pb->prior = pc;
            pc = pb;
            pb = pb->next;
        }
    }
    if (pa != NULL)
    {
        pc->next = pa;
    }
    if (pb != NULL)
    {
        pc->next = pb;
    }
    // pa或者pb为空的话，直接将后续的链表加上去
    return Lc; //返回头结点
}

void output_list(Linklist s)
{
    s = s->next;
    if (s == NULL)
    {
        printf("NULL"); //空链表输出NULL
        return;         //直接结束，不执行下面代码
    }
    while (s != NULL)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
    return;
}