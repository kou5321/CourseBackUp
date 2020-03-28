#include <stdio.h>
#include "string.h"
#include <stdlib.h>
#include <malloc.h>

#define Len 20000
#define Up (Len * 3 / 4)

typedef char ElemType;
typedef struct node //����˫������
{
    ElemType data; //������
    struct node *next;
    struct node *front; //ָ����
} List, *pList;         //������ͣ����ָ��

// pList pHead = (pList)malloc(sizeof(List));
// pList pTail = (pList)malloc(sizeof(List));
//�������ʽ�в�����������

char ans[Len + 5];
int forprt = 0;

pList creat(char *a, int n)
{
    /* nΪ����������*aΪ�������*/
    int i;
    pList pHead = (pList)malloc(sizeof(List));
    pList pTail = (pList)malloc(sizeof(List)); //����ͷָ���βָ��

    pList pt = pHead; // ptָ��ͷָ��

    pTail->front = pHead;
    pTail->next = NULL;
    pHead->next = pTail;
    pHead->front = NULL;             //�����յ�˫������
    pHead->data = pTail->data = '-'; //��ֵΪ'-',��ʾ�������û������

    for (i = 0; i < n; i++)
    {
        pList pNew = (pList)malloc(sizeof(List));
        pNew->data = a[i];  // ��ͨ��gets�õ����鴢���ַ�����Ȼ��ͨ����������ֵ
        pNew->front = pt; 
        pNew->next = pt->next;
        pt->next->front = pNew;
        pt->next = pNew;
        pt = pNew;  //�ƶ�ptָ��
    }
    return pHead;
}

pList insert(int m, char ch, pList pHead)
{
    int i = -1; // i=-1.�����λ�������

    pList pt = pHead, pNew = (pList)malloc(sizeof(List));

    while (i++ < m)
        pt = pt->next; //�ҵ�������λ��

    pNew->data = ch;
    pNew->next = pt;
    pNew->front = pt->front;
    pt->front->next = pNew;
    pt->front = pNew; //ע���ǲ����ҵ�λ�õ�ǰ��

    return pHead;
}

pList find_tail(pList pHead)
{
    pList pt = pHead->next;
    //while(!(pt->data == '-')) pt = pt ->next;
    while (pt->next != NULL)
        pt = pt->next;   //�����ַ����������ҵ�pTail
    return pt;
}

pList del(int m, pList pHead)
{
    pList pTail, point_tmp;
    pTail = find_tail(pHead);
    //���ptail
    pList p1 = NULL, p2 = NULL, p3 = NULL, p4 = NULL, pt = pHead; //��ָ����ø�ֵ NULL
    pList begin = pHead, end = pTail; 
    int boo = 1; //gcc��������֧��bool���ͣ�������int��ʾ�߼�
    int repeat, i = -1;

    // find position
    while (i++ < m - 2)
        pt = pt->next; // �ҵ�����λ��ǰ����ָ��

    //init for 'begin' and 'end'
    begin = pt;
    end = pt;
    i = 0;
    while (i++ < 4 && end->next != pTail)
        end = end->next; //�ҵ�����λ�ú�����ָ��

    while (boo && pt != pTail)
    {
        boo = 0; //�ж���û�з�������
        repeat = 1; //�����ظ��ĸ���
        while (pt != end) //pt��beginλ��
        {
            pt = pt->next;

            if (pt->front->data == pt->data) //pt���ƣ����data��ͬ���ͼ�����һ
                repeat++;
            else
                repeat = 1;

            if (repeat == 3)
            {
                boo = 1;
                if (pt->data == pt->next->data) //�Ѿ��������������ˣ��ٿ����ܲ��ܼ�������
                {
                    repeat++;
                    pt = pt->next;
                }

                if (repeat == 3)
                {
                    p3 = pt;
                    p2 = p3->front;
                    p1 = p2->front;
                    p1->front->next = p3->next;
                    p3->next->front = p1->front;
                    pt = pt->next; //��������������pt����
                    free(p1);
                    free(p2);
                    free(p3);
                }
                else
                {
                    p4 = pt;
                    p3 = p4->front;
                    p2 = p3->front;
                    p1 = p2->front;
                    p1->front->next = p4->next;
                    p4->next->front = p1->front;
                    pt = pt->next; //������4������pt����
                    free(p1);
                    free(p2);
                    free(p3);
                    free(p4);
                }

                break;
            }
        }

        if (boo && pt != pTail)
        {
            begin = pt;
            i = 0;
            while (i++ < 2 && begin->front != pHead)
                begin = begin->front;
            end = pt;
            i = 0;
            if (i++ < 1 && end->next != pTail)
                end = end->next;
            pt = begin; //��pt��begin��endָ���λ
        }
    }
    return pHead;
}

pList show(int boo, pList pHead) //��˫�������ֵ�浽����������
{

    pList pt = pHead->next;
    pList pTail = find_tail(pHead);

    if (pt == pTail)
        ans[forprt++] = '-'; //û����
    else
    {
        while (pt->next != NULL)
        {
            ans[forprt++] = pt->data; //���ݲ���data
            pt = pt->next;  //pt����
        }
    }

    ans[forprt++] = '\n'; //�����Ҫ�л���

    if (forprt >= Up || boo) //�������ͷ��
    {
        ans[forprt] = '\0'; //����һ��Ҫ�� \0 ��β
        printf("%s", ans); //���
        forprt = 0;
    }
    return pHead; //��ʵ����Ҫ������
}

int main(void)
{
    char a[10005];
    int n, k;
    pList pHead = NULL;

    //printf("�������ʼ����\n");
    gets(a); // ��ʼ����������
    //printf("�����������");
    scanf("%d", &n); // ����n�β���

    pHead = creat(a, strlen(a)); //������Ӧ��ʼ���������е�˫������

    for (k = 0; k < n; k++)
    {
        int m;
        char ch;

        scanf("%d ", &m); //�µ�����λ��

        ch = getchar(); // ����������ɫ

        // insert ch
        insert(m, ch, pHead);

        // delete all 3-same block, making it the right string
        del(m, pHead);

        // print the string
        show(k == n - 1 ? 1 : 0, pHead);
    }

    return 0;
}