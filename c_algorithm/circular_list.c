// 约瑟夫问题
#include <stdio.h>
#include <malloc.h>

//定义单向循环链表节点的存储结构
typedef struct lnode
{
    int num;            //数据域
    struct lnode *next; //指针域
} node, *L;             //节点类型，节点指针

void main()
{
    int amount, mount, start, circle, n, c;
    L head, p, q;      //定义头节点及中间辅助节点变量
    printf("amount:"); //输入一圈总人数
    scanf("%d", &amount);
    printf("exit:"); //输入需退出人数
    scanf("%d", &mount);
    printf("start:"); //设置计数开始点
    scanf("%d", &start);
    printf("circle:"); //输入循环报数值
    scanf("%d", &circle);
    head = (L)malloc(sizeof(node)); //生成头节点
    head->next = NULL;
    head->num = 0;
    q = head; //用来链接下一节点
    n = 0;    //用来给每个人记标号（1～amount）
    while (n++ < amount)
    {
        p = (L)malloc(sizeof(node)); //生成新节点
        p->next = NULL;
        p->num = n;
        q->next = p;
        q = p;
    }
    q->next = head->next; //形成循环链表
    //以上完成单向循环链表的建立

    p = head->next; //p赋为第一个节点
    q = head;       //q赋为p的上一节点，即头节点
    n = 1;          //用来寻找开始计数点的位置
    while (n++ < start)
    {
        p = p->next;
        q = q->next;
    } //在未找到开始计数点前，p，q依次后移
    //当退出循环时p，q分别位于指定位置，q为p的上一节点
    //接下来进行周期性节点删除，直到删除数目达到mount为止
    n = 1;
    while (n++ <= mount)
    {
        c = 1; //c作为循环报数值临时变量
        while (c++ < circle)
        {
            p = p->next;
            q = q->next;
        }                             //删除当前p指向的节点
        printf("delete%d\t", p->num); //输出删除节点的标号
        q->next = p->next;     //删除节点p
        p = p->next;  //p赋新值，原节点的下一节点 
    }
        printf("\n");
        n = 1;
        while (n++ <= amount - mount) //n计算输出剩余节点的数目，当n=amount-mount时全部输出完毕
        {
            printf("last%d\t", p->num); //输出剩余节点的标号
            p = p->next;                //p下移 
            }
            printf("\n");
        }