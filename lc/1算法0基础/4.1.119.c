/*
    返回杨辉三角第rowIndex行，从第0行开始
*/

int* getRow(int rowIndex, int* returnSize){
    int arr[rowIndex+1][rowIndex+1];
    int i, j, k;
    int *res = (int *)malloc(sizeof(int) * (rowIndex + 1));

    for (i = 0; i < rowIndex+1; ++i)
    {
        for (j = 0; j < i+1; ++j)
        {
            if (j == 0 || j == i)
                arr[i][j] = 1;
            else
            {
                arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
            }
        }
        if (rowIndex == i)
        {
            for(k = 0; k < rowIndex+1; ++k)
            {
                res[k] = arr[i][k];
            }
        }
    }
    *returnSize = rowIndex+1;
    return res;
}