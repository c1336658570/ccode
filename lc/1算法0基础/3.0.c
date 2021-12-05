/*
    将矩阵水平反转，并将0全替换为1，1替换为0
    核心代码
    src为n * m 的原矩阵，tar为新矩阵
    int i, j;
    for(i = 0; i < n; ++i) {                 // (1)
        for(j = 0; j < m; ++j) {             // (2)
            tar[i][j] = 1 - src[i][m-1-j];   // (3)
        }
    }

*/
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, 
int* returnSize, int** returnColumnSizes){
    int i, j, col;
    int **ret = (int **)malloc( sizeof(int *) * imageSize );        // (1)
    *returnColumnSizes = (int *)malloc( sizeof(int) * imageSize );  // (2)
    for(i = 0; i < imageSize; ++i) {
        col = imageColSize[i];                                      // (3)
        ret[i] = (int *)malloc( sizeof(int) * col );                // (4)
        (*returnColumnSizes)[i] = col;                              // (5)
        for(j = 0; j < col; ++j) {
            ret[i][j] = 1 - image[i][ col-1-j ];                    // (6)
        }
    }
    *returnSize = imageSize;                                        // (7)
    return ret;                                                     // (8)
}
