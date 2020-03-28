#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int Elemtype;
typedef struct node
{                      //������
    Elemtype data;     //���������
    struct node *next; //���ָ����
} Listnode, *Linklist; //�ڵ����ͣ��ڵ�ָ��

typedef struct dnode
{
    Elemtype data;              //���������
    struct dnode *prior, *next; //���ָ����
} DblNode, *DblList;            //�ڵ����ͣ��ڵ�ָ��

DblList createDblList(); //�˴�����˫��ѭ������
DblList mergeDblList(DblList, DblList);
void outputDblList(DblList); //���������NULL

void main()
{
    DblList L1, L2, L;
    printf("please input sequence1, end with -1:\t"); //�����뻻�н�β�����������������char��
    L1 = createDblList();
    printf("please input sequence2, end with -1:\t");
    L2 = createDblList();
    L = mergeDblList(L1, L2);
    printf("the result is:");
    outputDblList(L);
}

DblList createDblList() //����˫��ѭ������
{
    DblList head, pa, pb;
    int x = 0;
    scanf("%d", &x);
    if (x == -1)
        exit(1);
    head = (DblList)malloc(sizeof(DblNode));
    head->prior = head->next = head; //��ͷ������ָ��ָ���Լ�
    pa = head;
    while (x != -1)
    {
        pb = (DblList)malloc(sizeof(DblNode));
        pb->data = x;
        pb->prior = pa;
        pb->next = pa->next;
        pa->next->prior = pb;
        pa->next = pb;
        pa = pb;
        scanf("%d", &x);
    }
    return head; //����ͷָ��
}

DblList mergeDblList(DblList La, DblList Lb)
{
    DblList Lc, pa, pb, pc;
    // Lc = (DblList)malloc(sizeof(DblNode));
    Lc = La; //c�����ͷ��㣬ֱ����a����ͷ���͵ز��������Ϳռ临�Ӷ�
    pc = La; // pc�����ڲ����ǰһ�����
    pa = La->next;
    pb = Lb->next;               //pa��pb�Ǵ�����Ľ��
    while (pa != La && pb != Lb) //while (pa!=NULL && pb!=NULL) //La,Lb����Ϊ��
    {
        if (pa->data < pb->data) //Ϊ��ʵ�ַǽ���������Ҫ���з�������
        {
            pa->prior = pc;
            pa->next = pc->next;
            pc->next = pa;
            pc->next->prior = pa; //�����㣬����������
            pc = pa;
            pa = pa->next; //pc���ƣ�pa����
            // DblList ptr = pa->next;
            // pa->prior = pc;
            // pa->next = pc->next;
            // pc->next->prior = pa;
            // pc->next = pa;
            // pc = pa;
            // pa = ptr;
        }
        if (pa->data > pb->data)
        {
            // DblList ptr = pb->next;
            // pb->prior = pc;
            // pb->next = pc->next;
            // pc->next->prior = pb;
            // pc->next = pb;
            // pc = pb;
            // pb = ptr;
            pb->prior = pc;
            pb->next = pc->next;
            pc->next = pb;
            pc->next->prior = pb;
            pc = pb;
            pb = pb->next; //ͬ��
        }
        else //��ȵĻ������ظ�������������
        {
            pa->prior = pc;
            pa->next = pc->next;
            pc->next = pa;
            pc->next->prior = pa;
            pc = pa;
            pa = pa->next;
            
            pb->prior = pc;
            pb->next = pc->next;
            pc->next = pb;
            pc->next->prior = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    if (pa != La)
    {
        while (pa != La)
        {
            pa->prior = pc;
            pa->next = pc->next;
            pc->next = pa;
            pc->next->prior = pa;
            pc = pa;
            pa = pa->next; //�ظ���a����
        }
    }
    if (pb != Lb)
    {
        while (pb != Lb)
        {
            pb->prior = pc;
            pb->next = pc->next;
            pc->next = pb;
            pc->next->prior = pb;
            pc = pb;
            pb = pb->next; //�ظ���b����
        }
    }
    return Lc; //����ͷ���
}

void outputDblList(DblList s)
{
    DblList head = s;
    s = s->next;
    if (s == head)
    {
        printf("NULL"); //���������NULL
        return;         //ֱ�ӽ�������ִ���������
    }
    while (s != head)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
    return;
}