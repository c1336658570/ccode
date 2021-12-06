/*
    将矩阵水平反转（反转每一行），并将0全替换为1，1替换为0
    核心代码
    src为n * m 的原矩阵，tar为新矩阵
    int i, j;
    for(i = 0; i < n; ++i) {                 // (1)
        for(j = 0; j < m; ++j) {             // (2)
            tar[i][j] = 1 - src[i][m-1-j];   // (3)
        }
    }

*/
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes){
    int i, j, col;
    int **res = (int **)malloc(sizeof(int *) * imageSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * imageSize);
    
    for (i = 0; i < imageSize; ++i)
    {
        col = imageColSize[i];
        res[i] = (int *)malloc(sizeof(int) * col);
        (*returnColumnSizes)[i] = col;
        for (j = 0; j < col; ++j)
        {
            res[i][j] = 1 - image[i][col-1-j];
        }
    }
    *returnSize = imageSize;
    return res;
}
