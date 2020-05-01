#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef struct
{
    int weight;                 //Ȩֵ
    int parent, lchild, rchild; //˫�ף�����������������ע������һ����̬����
} HTNode, *HuffmanTree;         //��㣬ָ��
void Select(HuffmanTree HT, int x, int &s1, int &s2)
{
    int f = 0, g = 0;            //��ʼ��f��g�������൱��flag
    for (int i = 1; i <= x; i++) //ע��������һ��if�ͻ�ֱ��������һ��ѭ��
    {
        if (HT[i].parent != 0) //���˵i����Ѿ���������˫�׾�������
        {
            continue;
        }
        if (!f) //���f��0�����ڳ�ʼ��s1
        {
            f = 1;
            s1 = i;
        }
        else if (!g) //���g��0�����ڳ�ʼ��s2
        {
            g = 1;
            s2 = i;
            if (HT[s2].weight < HT[s1].weight) //��֤s2��Ȩֵ����s1
            {
                swap(s1, s2);
            }
        }
        else if (HT[i].weight < HT[s1].weight) //��ʱs2��s1��С
        {
            s2 = s1;
            s1 = i;
        }
        else if (HT[i].weight < HT[s2].weight) //��ʱs2��s1��С
        {
            s2 = i;
        }
    }
    // cout << " " << HT[s1].weight << " " << HT[s2].weight << endl;
}
void CreateHuffmanTree(HuffmanTree &HT, int n)
{
    if (n <= 1)
        return;             //n���С�ڵ���1�����轨����������
    int m = 2 * n - 1;      //m����Ҫ�����Ľڵ���
    HT = new HTNode[m + 1]; //����m+1���ռ䣬0�ŵ�Ԫδʹ��
    for (int i = 1; i <= m; i++)
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0; //һ��ʼ����ʼ��Ϊ0
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> HT[i].weight; //��̬��������ľͷ����
    }
    for (int i = n + 1; i <= m; i++)
    {
        int s1, s2;
        Select(HT, i - 1, s1, s2); //s1��s2����Ȩֵ��С�ı��
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight; //��i�������s1��s2��˫�ף�ȨֵΪs1��s2�ĺ�
    }
}

void readtree(HuffmanTree ht, int n)
{
    for (int i = 2 * n -1; i >=1; i--){
    if(n<=1)
    if(ht[i].lchild && ht[i].rchild){
        printf("�и�%d��Ϊ%d��%d\n",ht[i].weight, ht[ht[i].lchild].weight, ht[ht[i].rchild].weight);
    }
    }
}

int main()
{
    int n;
    scanf("%d", &n);                 //n��ľͷ����
    HuffmanTree H = new HTNode[100]; //����ռ�
    CreateHuffmanTree(H, n);         //������������
    int sum = 0;
    for (int i = n + 1; i <= 2 * n - 1; i++)
    {
        sum += H[i].weight; //˫��Ȩֵ��ӵõ�����
    }
    readtree(H, n);
    cout << sum << endl;
}