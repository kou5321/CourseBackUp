#include <stdlib.h>D
#include <stdio.h>

//��ʽջ
typedef int StackData;
typedef struct node
{
    StackData data;    //���
    struct node *link; //��ָ��
} StackNode;

typedef struct
{
    StackNode *top; //ջ��ָ��
} LinkStack;

void InitStack(LinkStack *S)
{
    (*S).top = NULL;
    //  ԭ����
    //S->top = NULL;
}

int Push(LinkStack *S, StackData x)
{
    StackNode *p;
    p = (StackNode *)malloc(sizeof(StackNode));
    p->data = x;
    p->link = (*S).top;
    (*S).top = p;
    return 1;   
}

int StackEmpty(LinkStack S){
    if(S.top == NULL) return 1;
    else return 0;
}

int Pop(LinkStack * S, StackData * x){ //ע����ָ��ȡ��ֵ
    StackNode * p;
    if(StackEmpty(*S)) return 0;
    p = (*S).top;
    (*S).top = p->link;
    * x = p->data;
    free(p);
    return 1;
}

int GetTop(LinkStack * S, StackData *x){
    if(StackEmpty(*S)) return 0;
    *x = (*S).top->data;
    return 1;
}

