#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int weight;
    int parent, lchild, rchild;
} HTNode, *HuffmanTree;

void Select(HuffmanTree HT, int n, int *s1, int *s2)
{
    int i, a = 0, b = 0; // a保存权值最小的那个的下标，b表示权值次小的那个的下标
    for (i = 1; i <= n; ++i)
    {
        if (HT[i].parent != 0)
        {
            continue;
        }
        if (HT[a].weight > HT[i].weight)
        {
            b = a;
            a = i;
            continue;
        }
        if (HT[b].weight > HT[i].weight)
        {
            b = i;
        }
    }
    *s1 = a;
    *s2 = b;
}

HuffmanTree CreatHuffmanTree(HuffmanTree HT, int n) //构造哈夫曼树
{
    if (n <= 1)
        return NULL;
    int m, i;

    m = 2 * n - 1;                                   //数组共2n-1个元素
    HT = (HTNode *)malloc(sizeof(HTNode) * (m + 1)); // 0号单元未用，HT[m]表示根节点
    for (i = 1; i <= m; ++i)                         //初始化
    {
        HT[i].lchild = HT[i].rchild = HT[i].parent = 0;
    }
    HT[0].weight = __INT_MAX__;
    for (i = 1; i <= n; ++i)
    {
        scanf("%d", &HT[i].weight); //输入前n个元素的weight值
    }

    for (i = n + 1; i <= m; i++) //合并产生的n-1个结点--构造Huffman树
    {
        int s1, s2;
        Select(HT, i - 1, &s1, &s2); //再HT[k](1 <= k <= i-1)中选择了两个其双亲域为0，且权值最小的结点，返回序号到s1和s2中
        //从F中删除s1和s2
        HT[s1].parent = i;
        HT[s2].parent = i;
        //将s1和s2作为左右孩子
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight; // i的权值为左右孩子全值的和
    }
    return HT;
}

int main(void)
{
    int i;
    HuffmanTree HT;

    HT = CreatHuffmanTree(HT, 5);

    for (i = 1; i <= 9; ++i)
    {
        printf("parent:%d,lchild:%d,rchild:%d,weight:%d\n",
               HT[i].parent, HT[i].lchild, HT[i].rchild, HT[i].weight);
    }

    return 0;
}