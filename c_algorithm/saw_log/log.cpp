#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int data;             //数据域
    int parent, lch, rch; //双亲，左子树，右子树
} HTNode, *HuffmanTree;   //实质上是一个静态链表

void Createhuffmantree(HuffmanTree &ht, int n)
{
    int m = 2 * n - 1;      // m是总的结点数
    ht = new HTNode[m + 1]; //分配m+1个空间，0号单元未使用
    int i, j, t;
    for (i = 1; i <= m; ++i) //从1开始，所有初值为0
    {
        ht[i].parent = 0;
        ht[i].lch = 0;
        ht[i].rch = 0;
    }

    int a[100]; //建立一个数组来储存输入的木头

    for (i = 0; i < n; i++)
    {
        int s;
        scanf("%d", &s);
        a[i] = s;
    }

    for (j = 0; j < n; j++) //冒泡排序,对输入的最终长度从小到大排序
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
        ht[i].data = a[i - 1]; //从1开始进行对静态链表赋值

    ht[1].parent = n + 1;
    ht[2].parent = n + 1; // 1和2的双亲是n+1
    ht[n + 1].lch = 1;
    ht[n + 1].rch = 2; // n+1的左子树和右子树是1和2
    ht[n + 1].data = ht[1].data + ht[2].data; // n+1的data值是1和2的data值相加

    for (i = 2; i <= n - 1; i++)
    {
        //建立第n+i个结点的时候，右子树是i+1，左子树是n+i-1,data值左子树和右子树相加
        ht[n + i].lch = (n + i - 1); 
        ht[n + i].rch = (i + 1); 
        ht[n + i].data = ht[n + i - 1].data + ht[i + 1].data;
        //右子树是i+1，左子树是n+i-1，双亲是n+i
        ht[n + i - 1].parent = n + i;
        ht[i + 1].parent = n + i;
    }
}

int htsum(HuffmanTree ht, int n)
{
    int sumn = 0;
    for (int i = n + 1; i < 2 * n; i++) //对于叶子的双亲的data值进行叠加就是最小的花费
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
    HuffmanTree A; //定义霍夫曼树

    int x;
    scanf("%d", &x); //总的个数
    Createhuffmantree(A, x); //建立霍夫曼树

    int Sum = 0;
    Sum = htsum(A, x); //最小的花费
    readtree(A,x);
    printf("%d", Sum);
}
