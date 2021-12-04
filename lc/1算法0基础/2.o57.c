
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