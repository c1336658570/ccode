
# include <stdbool.h>

int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    if(target <= 0 ){
        return NULL;
    }
    int** res = (int**)malloc(sizeof(int*)*target);
    *returnColumnSizes = (int*)malloc(sizeof(int)*target);

    *returnSize  = 0;

    int left = 1 , right = 1 , sum = 0 , len = target /2;
    while(left <= len){
        if(sum == target){
            res[*returnSize] = (int*)malloc(sizeof(int) * (right - left));
            (*returnColumnSizes)[*returnSize] = right - left ;
            for(int  i = left ; i < right; i++){
                res[*returnSize][i-left] = i; 
            }
            (*returnSize)++;
            sum -= left;
            left++;
        }
        if(sum < target){
            sum += right;
            right++;
        }
        if(sum > target){
            sum -= left;
            left++;
        }
    }

    return res;
}

int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int i, j, k, t, p, max, sum;
    int **res = (int **)malloc(sizeof(int *) * target);
    int *len = (int *)malloc(sizeof(int) * target);
    
    *returnSize = 0;
    max = (target+1)/2;
    k = 0;
    t = 0;
    for (i = 0; i < target; ++i)
    {
        res[i] = (int *)malloc(sizeof(int) * target);
    }

    for (i = 1; i <=max; ++i)
    {
        sum = 0;
        p = t;
        for (j = i; j <= max; ++j)
        {
            sum += j;
            if (sum < target)
            {
                res[k][t] = j;
                t++;
                continue;
            }
            else if (sum == target)
            {
                res[k][t] = j;
                t++;
                len[k] = t;
                k++;
                break;
            }
            else
            {
                t = p;
                break;
            }
        }
    }
    *returnSize = k;
    *returnColumnSizes = len;
    return res;
}