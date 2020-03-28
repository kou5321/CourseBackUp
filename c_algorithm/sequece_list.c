#include <stdio.h>
#include <stdlib.h>

#define ListSize 100 //最大长度
#define Listincrement 100

typedef int Elemtype;
typedef struct
{
    Elemtype *data; //存储地址基址
    int length;     //当前元素个数
    int listsize;   //当前分配的存储容量
} seqlist;

/*初始化*/
void InitList(seqlist *L)
{
    L->data = (Elemtype *)malloc(ListSize * sizeof(Elemtype));
    if (L->data == NULL)
    {
        printf("分配失败\n");
        exit(1);
    }
    L->length = 0;
}

/*建立顺序表*/
void Createlist(seqlist *L)
{
    int i;
    printf("input the length is ");
    scanf("%d", &L->length);
    for (i = 0; i < L->length; i++)
    {
        printf("input data is:");
        scanf("%d", &(L->data[i]));
    }
}

/*按值查找：查找x在表中的位置，若查找成功， 返回x的位置，否则返回-1 */
int Find(seqlist *L, Elemtype x)
{
    int i = 0;
    while (i < L->length && L->data[i] != x)
    {
        i++;
        if (i < L->length)
            return i;
        else
            return -1;
    }
}

/*按值查找：判断x是否在表中*/
int Isin(seqlist *L, Elemtype x)
{
    int i = 0, found = 0;
    while (i < L->length && !found)
    {
        if (L->data != x)
            i++;
        else
            found = 1;
    }
    return found;
}

int Length(seqlist *L)
{
    return L->length;
}

Elemtype Getdata(seqlist *L, int i)
{
    if (i >= 1 && i <= L->length)
    {
        return L->data[i - 1];
    }
    else
    {
        printf{"参数不合理"};
    }
}

int Next(seqlist *L, Elemtype x)
{
    int i = Find(x);
    if (i >= 0 && i <= L->length - 1)
        return i + 1;
    else
        return -1;
}

int Prior(seqlist *L, Elemtype x)
{
    int i = Find(x);
    if (i >= 0 && i <= L->length - 1)
        return i - 1;
    else
        return -1;
}

int Insert(seqlist *L, Elemtype x, int i){
    //在表中第 i 个位置(1<=i<=n)插入新元素 x         // i 计数从1起 
    int *q, *p, *newbase;
    if(i<1||i>L->length+1) return 0;
    if(L->length>=)
}