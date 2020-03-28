#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define overflow -2

typedef char StackData;

//˳��ջ�����ͱ�ʾ:
typedef struct
{                    //˳��ջ����
    StackData *base; //ջ��ָ��
    StackData *top;  //ջ��ָ��
    int stacksize;   //��ǰ�ѷ���Ĵ洢�ռ�
} seqStack;

//��ջ��
int stackEmpty(seqStack *S)
{
    if (S->top == S->base)
        return 1; //��ջ��,���򷵻�1
    else
        return 0; //���򷵻�0
}

int stackFull(seqStack *S)
{
    if (S->top - S->base >= S->stacksize)
        return 1; //��ջ��,���򷵻�1
    else
        return 0; //���򷵻�0
}

//��ʼ��
void initStack(seqStack *S)
{
    S->base = (StackData *)malloc(sizeof(StackData));
    if (!S->base)
        exit(1);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
}

// int main(int argc, char const *argv[])
// {
//     seqStack *S;
//     S = (seqStack *)malloc(sizeof(seqStack));
//     initStack(S);
//     return 0;
// }

//��ջ
void Push(seqStack *S, StackData x)
{
    //����Ԫ��xΪ�µ�ջ��Ԫ��
    if (stackFull(S))
    {
        S->base = (StackData *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(StackData));
        //s->base���ܸĶ�
        if(!S->base) exit(overflow);
        S->top = S->base + S->stacksize;
        S->stacksize+=STACKINCREMENT;  //׷�Ӵ洢�ռ�
    }
    *(S->top)=x;
    (S->top)++;
}   //֮ǰ��Ԫ�أ�����������������������

int getTop(seqStack * S, StackData *x){
    //��ջ�շ���0, ����ջ��Ԫ�ض���x������1
    if(stackEmpty(S)) return 0;
    *x = *(S->top-1);  //ע��topָ����ջ��������һ��
    return 1;
}

int pop(seqStack *S, StackData * x){
    //��ջ�շ���0, ����ջ��Ԫ���˳���x������1
    if(stackEmpty(S)) return 0;
    (S->top)--;
    *x = *(S->top);
    return 1;
}



