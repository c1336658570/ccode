/*
给你一个二维整数数组 matrix， 返回 matrix 的 转置矩阵 。

矩阵的 转置 是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[1,4,7],[2,5,8],[3,6,9]]
示例 2：

输入：matrix = [[1,2,3],[4,5,6]]
输出：[[1,4],[2,5],[3,6]]
*/

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    int **arr = (int **)malloc(sizeof(int *) *matrixColSize[0]);
    *returnColumnSizes = (int *)malloc(sizeof(int) *matrixColSize[0]);
    int i, j;

    for (i = 0; i < matrixColSize[0]; ++i)
    {
        arr[i] = (int *)malloc(sizeof(int) *matrixSize);
        (*returnColumnSizes)[i] = matrixSize;
        for (j = 0; j < matrixSize; ++j)
        {
            arr[i][j] = matrix[j][i];
        }
    }
    *returnSize = matrixColSize[0];
    return arr;
}