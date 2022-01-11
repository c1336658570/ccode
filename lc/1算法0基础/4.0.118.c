/*
    杨辉三角
*/

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int i, j;
    int **res = (int **)malloc(sizeof(int*) *numRows);
    *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);

    for (i = 0; i < numRows; ++i)
    {
        res[i] = (int *)malloc(sizeof(int) * (i+1));
        (*returnColumnSizes)[i] = i + 1;
        for (j = 0; j < i+1; ++j)
        {
            if (j == 0 || j == i)
                res[i][j] = 1;
            else
            {
                res[i][j] = res[i-1][j] + res[i-1][j-1];
            }
        }
    }
    *returnSize = numRows;
    return res;
}
