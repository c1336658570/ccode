/*
给你一个 m 行 n 列的二维网格 grid 和一个整数 k。你需要将 grid 迁移 k 次。

每次「迁移」操作将会引发下述活动：

位于 grid[i][j] 的元素将会移动到 grid[i][j + 1]。
位于 grid[i][n - 1] 的元素将会移动到 grid[i + 1][0]。
位于 grid[m - 1][n - 1] 的元素将会移动到 grid[0][0]。
请你返回 k 次迁移操作后最终得到的 二维网格。

示例 1：

输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
输出：[[9,1,2],[3,4,5],[6,7,8]]
示例 2：

输入：grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
输出：[[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]
示例 3：

输入：grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
输出：[[1,2,3],[4,5,6],[7,8,9]]
*/

int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int *) * gridSize);
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * gridSize);
    int i, j, t = k;

    for (i = 0; i < gridSize; ++i)
    {
        (*returnColumnSizes)[i] = gridColSize[i];
        res[i] = (int *)malloc(sizeof(int) * gridColSize[i]);
    }
    if (t == 0)
    {
        return grid;
    }

    while(t)
    {
        for (i = 0; i < gridSize; ++i)
        {   
            for (j = 0; j < gridColSize[i]; ++j)
            {
                if (i == gridSize-1 && j == gridColSize[i]-1)
                {
                    res[0][0] = grid[i][j];
                }
                else if (j < gridColSize[i] - 1)
                {
                    res[i][j+1] = grid[i][j];
                }
                else
                {
                    res[i+1][0] = grid[i][j];
                }
            }
        }
        for (i = 0; i < gridSize; ++i)
        {
            for (j = 0; j <gridColSize[i]; ++j)
            {
                grid[i][j] = res[i][j];
            }
        }

        t--;
    }
    *returnSize = gridSize;
    return res;
}

int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
    int** arr = (int**)calloc(gridSize,sizeof(int*));
    *returnColumnSizes=(int*)calloc(gridSize,sizeof(int));
    int i,j,row,col;
    for (i=0; i<gridSize; i++){
        arr[i] = (int*)calloc(gridColSize[i],sizeof(int));
    }
    for (i=0; i<gridSize; i++){    
        for (j=0; j<gridColSize[i]; j++){
            row = (gridColSize[i]*i+j+k)/gridColSize[i]%gridSize;
            col = (gridColSize[i]*i+j+k)%gridColSize[i];
            arr[row][col] = grid[i][j];
        }
        (*returnColumnSizes)[i] = gridColSize[i];
    }
    *returnSize = gridSize;
    return arr;
}