/*
坐标型
有一个机器人的位于一个 m × n 个网格左上角。
机器人每一时刻只能向下或者向右移动一步。机器人试图达到网格的右下角。
问有多少条不同的路径？
n和m均不超过100
且答案保证在32位整数可表示范围内。
现在考虑网格中有障碍物，那样将会有多少条不同的路径？
网格中的障碍和空位置分别用 1 和 0 来表示。

输入：
obstacleGrid = [[0]]
输出：
1
解释：
只有一个点

样例 2：
输入：
obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：
2
*/

/*m,n表示二维数组长度*/
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize)
{
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];
    if (m == 0 || n == 0)
        return 0;
    int i, j;
    int f[m][n];
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (obstacleGrid[i][j] == 1)
                f[i][j] == 0;
            else
            {
                if (i == 0 && j == 0)
                    f[i][j] = 1;
                else
                {
                    f[i][j] = 0;
                    if (i > 1)
                        f[i][j] += f[i-1][j];
                    if (j > 1)
                        f[i][j] += f[i][j-1];
                }
            }
        }
    }
    return f[m-1][n-1];
}

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];
    if (m == 0 || n == 0)
        return 0;
    int f[m][n];
    int i, j;
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            if (obstacleGrid[i][j] == 1)
                f[i][j] = 0;
            else
            {
                if (i == 0 && j == 0)
                    f[i][j] = 1;
                else if (i == 0 && j != 0)
                    f[i][j] = f[i][j-1];
                else if (i != 0 && j == 0)
                    f[i][j] = f[i-1][j];
                else
                    f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
    }
    return f[m-1][n-1];
}