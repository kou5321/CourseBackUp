#include <stdlib.h>D
#include <stdio.h>

typedef int QueueData;

typedef struct node
{
    QueueData data; //���н������
    struct node *link;
} QueueNode;

typedef struct
{
    QueueNode *rear, *front;
} LinkQueue;

//�����е���Ҫ����
//��ʼ��
void InitQueue(LinkQueue *Q)
{
    Q->rear = Q->front = (QueueNode *)malloc(sizeof(QueueNode));
    if (!Q->front)
        exit(1);
    Q->front->link = NULL;
}

//ȡ��ͷԪ��
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
    Q->rear->link = p; //���
    Q->rear = p;
    return 1;
}

int DelQueue(LinkQueue *Q, QueueData *x)
{
    if (Q->rear == Q->front)
        return 0; //�жӿ�
    QueueNode *p = Q->front->link;
    *x = p->data;             //�����ͷ��ֵ
    Q->front->link = p->link; //�¶�ͷ
    if (Q->rear == p)
        Q->rear = Q->front; //ɾ����
    free(p);
    return 1;
}

 