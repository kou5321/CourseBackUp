#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int QueueData;

typedef struct
{
    QueueData *data; // 注意区别
    int front;
    int rear;
} SeqQueue;

void InitQueue(SeqQueue *Q)
{
    Q->data = (QueueData *)malloc(MAXSIZE * sizeof(QueueData)); // 注意
    if (!Q->data)
        exit(1);
    Q->rear = Q->front = 0;
}

int QueueEmpty(SeqQueue *Q)
{
    return Q->rear == Q->front;
}

int QueueFull(SeqQueue *Q)
{
    return (Q->rear + 1) % MAXSIZE == Q->front;
}

int EnQueue(SeqQueue *Q, QueueData x) //进入从队尾进入
{
    if (QueueFull(Q))
        return 0;
    Q->data[Q->rear] = x;              // 数据域是个数组
    Q->rear = (Q->rear + 1) % MAXSIZE; //前进方式
    return 1;
}

int DeQueue(SeqQueue *Q, QueueData *x)
{ //删除从队头删除
    if (QueueEmpty(Q))
        return 0;
    *x = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1;
}

int GetFront(SeqQueue *Q, QueueData *x)
{ 
    if (QueueEmpty(Q))
        return 0;
    *x = Q->data[Q->front];
    return 1;
}