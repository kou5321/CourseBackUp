#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define overflow -2

typedef char StackData;

//顺序栈的类型表示:
typedef struct
{                    //顺序栈定义
    StackData *base; //栈底指针
    StackData *top;  //栈顶指针
    int stacksize;   //当前已分配的存储空间
} seqStack;

//判栈空
int stackEmpty(seqStack *S)
{
    if (S->top == S->base)
        return 1; //判栈空,空则返回1
    else
        return 0; //否则返回0
}

int stackFull(seqStack *S)
{
    if (S->top - S->base >= S->stacksize)
        return 1; //判栈满,满则返回1
    else
        return 0; //否则返回0
}

//初始化
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

//入栈
void Push(seqStack *S, StackData x)
{
    //插入元素x为新的栈顶元素
    if (stackFull(S))
    {
        S->base = (StackData *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(StackData));
        //s->base可能改动
        if(!S->base) exit(overflow);
        S->top = S->base + S->stacksize;
        S->stacksize+=STACKINCREMENT;  //追加存储空间
    }
    *(S->top)=x;
    (S->top)++;
}   //之前的元素？？？？？？？？？？？？

int getTop(seqStack * S, StackData *x){
    //若栈空返回0, 否则栈顶元素读到x并返回1
    if(stackEmpty(S)) return 0;
    *x = *(S->top-1);  //注意top指针在栈顶的上面一格
    return 1;
}

int pop(seqStack *S, StackData * x){
    //若栈空返回0, 否则栈顶元素退出到x并返回1
    if(stackEmpty(S)) return 0;
    (S->top)--;
    *x = *(S->top);
    return 1;
}



