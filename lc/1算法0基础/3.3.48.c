/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。
示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[[7,4,1],[8,5,2],[9,6,3]]
示例 2：

输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
示例 3：

输入：matrix = [[1]]
输出：[[1]]
示例 4：

输入：matrix = [[1,2],[3,4]]
输出：[[3,1],[4,2]]
*/

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i, j, k, t;
    int arr[matrixSize][matrixSize];

    for (i = 0; i < matrixSize; ++i)
    {
        for (j = 0;j < matrixSize; ++j)
        {
            arr[i][j] = matrix[i][j];
        }
    }

    for (i = 0; i < matrixSize; ++i)
    {
        for (j = 0; j < matrixSize; ++j)
        {
            matrix[i][j] = arr[matrixSize - 1-j][i];
        }
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b, *b = t;
}

void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int i = matrixSize, j, t;

    //水平翻转
    // for (i = 0; i < matrixSize / 2; ++i) {
    //     for (j = 0; j < matrixSize; ++j) {
    //         swap(&matrix[i][j], &matrix[matrixSize - i - 1][j]);
    //     }
    // }

    //作用同上，  水平翻转
    for (i = 0; i < matrixColSize[0]; ++i)
    {
        for (j = 0; j < matrixSize/2; ++j)
        {
            t = matrix[j][i];
            matrix[j][i] = matrix[matrixSize-1-j][i];
            matrix[matrixSize-1-j][i] = t;
            
        }
    }

    //主对角线元素翻转
    for (i = 0; i < matrixSize; ++i)
    {
        for (j = 0; j < i; ++j)
        {
            t = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = t;
        }
    }
}