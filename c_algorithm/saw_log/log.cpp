#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;             //������
    int parent, lch, rch; //˫�ף���������������
} HTNode, *HuffmanTree;   //ʵ������һ����̬����

void Createhuffmantree(HuffmanTree &ht, int n)
{
    int m = 2 * n - 1;      // m���ܵĽ����
    ht = new HTNode[m + 1]; //����m+1���ռ䣬0�ŵ�Ԫδʹ��
    int i, j, t;
    for (i = 1; i <= m; ++i) //��1��ʼ�����г�ֵΪ0
    {
        ht[i].parent = 0;
        ht[i].lch = 0;
        ht[i].rch = 0;
    }

    int a[100]; //����һ�����������������ľͷ

    for (i = 0; i < n; i++)
    {
        int s;
        scanf("%d", &s);
        a[i] = s;
    }

    for (j = 0; j < n; j++) //ð������,����������ճ��ȴ�С��������
    {
        for (i = 0; i < n - 1; i++) 
            if (a[i] > a[i + 1])
            {
                t = a[i];
                a[i] = a[i + 1];
                a[i + 1] = t;
            }
    }
    // for (i = 0; i < n; i++)
    //     printf("%d\n", a[i]);

    for (i = 1; i <= n; ++i)
        ht[i].data = a[i - 1]; //��1��ʼ���жԾ�̬����ֵ

    ht[1].parent = n + 1;
    ht[2].parent = n + 1; // 1��2��˫����n+1
    ht[n + 1].lch = 1;
    ht[n + 1].rch = 2; // n+1������������������1��2
    ht[n + 1].data = ht[1].data + ht[2].data; // n+1��dataֵ��1��2��dataֵ���

    for (i = 2; i <= n - 1; i++)
    {
        //������n+i������ʱ����������i+1����������n+i-1,dataֵ�����������������
        ht[n + i].lch = (n + i - 1); 
        ht[n + i].rch = (i + 1); 
        ht[n + i].data = ht[n + i - 1].data + ht[i + 1].data;
        //��������i+1����������n+i-1��˫����n+i
        ht[n + i - 1].parent = n + i;
        ht[i + 1].parent = n + i;
    }
}

int htsum(HuffmanTree ht, int n)
{
    int sumn = 0;
    for (int i = n + 1; i < 2 * n; i++) //����Ҷ�ӵ�˫�׵�dataֵ���е��Ӿ�����С�Ļ���
        sumn = sumn + ht[i].data;
    return sumn;
}

void readtree(HuffmanTree ht, int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
        printf("%d %d\n", i, ht[i].data);
}

int main()
{
    HuffmanTree A; //�����������

    int x;
    scanf("%d", &x); //�ܵĸ���
    Createhuffmantree(A, x); //������������

    int Sum = 0;
    Sum = htsum(A, x); //��С�Ļ���
    readtree(A,x);
    printf("%d", Sum);
}
