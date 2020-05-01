#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;
    int parent, lch, rch;
} HTNode, *HuffmanTree;

void Createhuffmantree(HuffmanTree &ht, int n)
{
    int m = 2 * n - 1;
    ht = new HTNode[m + 1];
    int i, j, t;
    for (i = 1; i <= m; ++i)
    {
        ht[i].parent = 0;
        ht[i].lch = 0;
        ht[i].rch = 0;
    }

    int a[100];

    printf("PLEASE INPUT\n");

    for (i = 0; i < n; i++)
    {
        int s;
        scanf("%d", &s);
        a[i] = s;
    }

    printf("\n");
    for (j = 0; j < n; j++)
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
        ht[i].data = a[i - 1];

    ht[1].parent = n + 1;
    ht[2].parent = n + 1;
    ht[n + 1].lch = 1;
    ht[n + 1].rch = 2;
    ht[n + 1].data = ht[1].data + ht[2].data;

    for (i = 2; i <= n - 1; i++)
    {
        ht[n + i].lch = (n + i - 1);
        ht[n + i].rch = (i + 1);
        ht[n + i].data = ht[n + i - 1].data + ht[i + 1].data;

        ht[n + i - 1].parent = n + i;
        ht[i + 1].parent = n + i;
    }
}

int htsum(HuffmanTree ht, int n)
{
    int sumn = 0;
    for (int i = n + 1; i < 2 * n; i++)
        sumn = sumn + ht[i].data;
    return sumn;
}

void readtree(HuffmanTree ht, int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
        printf("%d     ,%d\n", i, ht[i].data);
}

int main()
{
    HuffmanTree A;

    int x;
    scanf("%d", &x);
    Createhuffmantree(A, x);

    int Sum = 0;
    Sum = htsum(A, x);
    //readtree(A,x);
    printf("%d", Sum);
}
