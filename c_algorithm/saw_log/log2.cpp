#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct
{
    int weight;                 //权值
    int parent, lchild, rchild; //双亲，左子树，右子树，注意这是一个静态链表
} HTNode, *HuffmanTree;         //结点，指针
void Select(HuffmanTree HT, int x, int &s1, int &s2)
{
    int f = 0, g = 0;            //初始化f，g，作用相当于flag
    for (int i = 1; i <= x; i++) //注意满足了一个if就会直接跳到下一个循环
    {
        if (HT[i].parent != 0) //如果说i结点已经被分配了双亲就跳过它
        {
            continue;
        }
        if (!f) //如果f是0，用于初始化s1
        {
            f = 1;
            s1 = i;
        }
        else if (!g) //如果g是0，用于初始化s2
        {
            g = 1;
            s2 = i;
            if (HT[s2].weight < HT[s1].weight) //保证s2的权值大于s1
            {
                swap(s1, s2);
            }
        }
        else if (HT[i].weight < HT[s1].weight) //此时s2和s1最小
        {
            s2 = s1;
            s1 = i;
        }
        else if (HT[i].weight < HT[s2].weight) //此时s2和s1最小
        {
            s2 = i;
        }
    }
    // cout << " " << HT[s1].weight << " " << HT[s2].weight << endl;
}
void CreateHuffmanTree(HuffmanTree &HT, int n)
{
    if (n <= 1)
        return;             //n如果小于等于1，无需建立霍夫曼树
    int m = 2 * n - 1;      //m是需要建立的节点数
    HT = new HTNode[m + 1]; //分配m+1个空间，0号单元未使用
    for (int i = 1; i <= m; i++)
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0; //一开始都初始化为0
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> HT[i].weight; //静态链表，输入木头长度
    }
    for (int i = n + 1; i <= m; i++)
    {
        int s1, s2;
        Select(HT, i - 1, s1, s2); //s1和s2代表权值最小的编号
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight; //第i个结点是s1和s2的双亲，权值为s1和s2的和
    }
}

void readtree(HuffmanTree ht, int n)
{
    for (int i = 2 * n -1; i >=1; i--){
    if(n<=1)
    if(ht[i].lchild && ht[i].rchild){
        printf("切割%d成为%d和%d\n",ht[i].weight, ht[ht[i].lchild].weight, ht[ht[i].rchild].weight);
    }
    }
}

int main()
{
    int n;
    scanf("%d", &n);                 //n是木头数量
    HuffmanTree H = new HTNode[100]; //分配空间
    CreateHuffmanTree(H, n);         //建立霍夫曼树
    int sum = 0;
    for (int i = n + 1; i <= 2 * n - 1; i++)
    {
        sum += H[i].weight; //双亲权值相加得到花费
    }
    readtree(H, n);
    cout << sum << endl;
}