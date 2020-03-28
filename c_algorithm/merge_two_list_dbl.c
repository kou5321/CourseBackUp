#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType;
typedef struct node
{                      //������
    ElemType data;     //���������
    struct node *next, *prior; //���ָ����
} Listnode, *Linklist; //�ڵ����ͣ��ڵ�ָ��

Linklist create_list(); //�˴����˵�����
Linklist merge_list(Linklist, Linklist);
void output_list(Linklist); //���������NULL

void main()
{
    Linklist L1, L2, L;
    printf("please input sequence1, end with -1:\t"); //�����뻻�н�β�����������������char��
    L1 = create_list();
    printf("please input sequence2, end with -1:\t");
    L2 = create_list();
    L = merge_list(L1, L2);
    printf("the result is:");
    output_list(L);
}

Linklist create_list() //����������ֵ
{
    int x;
    Linklist head, pa, pb; //ͷ��������ָ��,pb�������ٿռ䣬pa��������pb
    scanf("%d", &x);
    if(x==1) exit(1); //�����һ������Ϊ-1���쳣�˳�
    head = (Linklist)malloc(sizeof(Listnode)); //����ͷ���
    pa = head;
    while (x != -1)
    {
        pb = (Linklist)malloc(sizeof(Listnode));
        pb->data = x;
        pa->next = pb;
        pb->prior = pa;
        pa = pb;
        scanf("%d", &x);
    }
    pb->next = NULL;
    return head; //����ͷ���
}

Linklist merge_list(Linklist La, Linklist Lb)
{
    Linklist Lc, pa, pb, pc;
    Lc = La; //c�����ͷ��㣬ֱ����a����͵ز��������Ϳռ临�Ӷ�
    pc = La;
    pa = La->next;
    pb = Lb->next;   //pa,pb,pcΪָ��
    while (pa && pb) //while (pa!=NULL && pb!=NULL) //La,Lb����Ϊ��
    {
        if (pa->data < pb->data) //Ϊ��ʵ�ַǽ���������Ҫ���з�������
        {
            pc->next = pa;
            pa->prior = pc;
            pc = pa;
            pa = pa->next;
        }
        if (pa->data > pb->data)
        {
            pc->next = pb;
            pb->prior = pc;
            pc = pb;
            pb = pb->next;
        }
        else //��ȵĻ������ظ�������������
        {
            pc->next = pa;
            pa->prior = pc;
            pc = pa;
            pa = pa->next;

            pc->next = pb;
            pb->prior = pc;
            pc = pb;
            pb = pb->next;
        }
    }
    if (pa != NULL)
    {
        pc->next = pa;
    }
    if (pb != NULL)
    {
        pc->next = pb;
    }
    // pa����pbΪ�յĻ���ֱ�ӽ��������������ȥ
    return Lc; //����ͷ���
}

void output_list(Linklist s)
{
    s = s->next;
    if (s == NULL)
    {
        printf("NULL"); //���������NULL
        return;         //ֱ�ӽ�������ִ���������
    }
    while (s != NULL)
    {
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
    return;
}