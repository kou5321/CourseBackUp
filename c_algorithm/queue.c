#include <stdlib.h>D
#include <stdio.h>

typedef int QueueData;

typedef struct node
{
    QueueData data; //队列结点数据
    struct node *link;
} QueueNode;

typedef struct
{
    QueueNode *rear, *front;
} LinkQueue;

//链队列的主要操作
//初始化
void InitQueue(LinkQueue *Q)
{
    Q->rear = Q->front = (QueueNode *)malloc(sizeof(QueueNode));
    if (!Q->front)
        exit(1);
    Q->front->link = NULL;
}

//取队头元素
int GetFront(LinkQueue *Q, QueueData *x)
{
    if (QueueEmpty(Q))
        return 0;
    (*x) = Q->front->link->data;
    return 1;
}

int EnQueue(LinkQueue *Q, QueueData y)
{
    QueueNode *p = (QueueData *)malloc(sizeof(QueueNode));
    p->data = y;
    p->link = NULL;
    Q->rear->link = p; //入队
    Q->rear = p;
    return 1;
}

int DelQueue(LinkQueue *Q, QueueData *x)
{
    if (Q->rear == Q->front)
        return 0; //判队空
    QueueNode *p = Q->front->link;
    *x = p->data;             //保存队头的值
    Q->front->link = p->link; //新队头
    if (Q->rear == p)
        Q->rear = Q->front; //删空了
    free(p);
    return 1;
}

 