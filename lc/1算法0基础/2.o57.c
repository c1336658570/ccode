/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。

序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。
示例 1：

输入：target = 9
输出：[[2,3,4],[4,5]]
示例 2：

输入：target = 15
输出：[[1,2,3,4,5],[4,5,6],[7,8]]

*/


# include <stdbool.h>
# include <stdlib.h>

int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int i, j, k, t, p, max, sum;
    
    *returnSize = 0;
    max = (target+1)/2;
    k = 0;
    t = 0;

    int **res = (int **)malloc(sizeof(int *) * max);
    int *len = (int *)malloc(sizeof(int) * max);

    for (i = 1; i <=max; ++i)
    {
        sum = 0;
        t = 0;
        for (j = i; ; ++j)
        {
            sum += j;
            if (sum < target)
            {
                t++;
                continue;
            }
            else if (sum == target)
            {
                t++;
                res[k] = (int *)malloc(sizeof(int) * t);
                len[k] = t;
                for (t-=1; t >= 0; t--)
                    res[k][t] = j--;
                k++;
                break;
            }
            else
            {
                break;
            }
        }
    }
    *returnSize = k;
    *returnColumnSizes = len;
    return res;
}

/*
求和公式

target = (x+y) (y-x+1)/ 2
y方+y−x方+x−2×target=0 
解关于Y的一元二次方程a = 1, b = 1, c = −x方+x−2×target
判别式 b^2-4ac开根需要为整数
最后的求根公式的分子需要为偶数，因为分母为2
*/

int **findContinuousSequence(int target, int *returnSize, int **returnColumnSizes)
{
    int **res;
    int *col;
    long long int x, y;
    int m = 0;
    int limit = target / 2;
    long long int delta;
    double delta_sqrt;

    res = (int **)malloc(sizeof(int *) * target);
    col = (int *)malloc(sizeof(int) * target);

    for (x = 1; x <= limit; x++)
    {
        delta = 4 * x * x - 4 * x + 8 * target + 1;
        delta_sqrt = sqrt(delta);
        if (((delta_sqrt - (int)delta_sqrt) == 0) && (((int)delta_sqrt - 1) % 2 == 0))
        {
            y = (delta_sqrt - 1) / 2;
            col[m] = y - x + 1;
            res[m] = (int *)malloc(sizeof(int) * col[m]);
            for (int i = x; i <= y; i++)
                res[m][i - x] = i;
            m++;
        }
    }

    *returnSize = m;
    *returnColumnSizes = col;
    return res;
}

//滑动窗口

int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){

    int mid=target/2;//中间值
    int **res=malloc(sizeof(int*)*mid);
    int *col=malloc(sizeof(int)*mid);
    int x=1,y=2;
    int sum=x+y;
    int m=0;//m是下标
    while(x<=mid)
    {
        if(sum<target)
        {
            sum += ++y;
        }
        else if(sum>target)
        {
            sum -= x++;
        }
        else
        {
            col[m]=y-x+1;//得到元素个数
            res[m]=malloc(sizeof(int)*col[m]);//申请对应大小的内存
            for(int i=0;i<col[m];i++)
            {
                res[m][i]=i+x;
            }
            m++;
            sum -= x++;
        }
    }
    *returnSize=m;
    *returnColumnSizes=col;//col数组中存储的其实是每一个序列的元素个数
    return res;
}

