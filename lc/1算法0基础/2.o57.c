
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

