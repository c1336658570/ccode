/*
给你两个大小为 n x n 的二进制矩阵 mat 和 target 。现 以 90 度顺时针轮转 矩阵 mat 中的元素
 若干次 ，如果能够使 mat 与 target 一致，返回 true ；否则，返回 false 。

示例 1：
输入：mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
输出：true
解释：顺时针轮转 90 度一次可以使 mat 和 target 一致。

示例 2：
输入：mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
输出：false
解释：无法通过轮转矩阵中的元素使 equal 与 target 一致。

示例 3：
输入：mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
输出：true
解释：顺时针轮转 90 度两次可以使 mat 和 target 一致。
*/

# include <stdbool.h>

bool findRotation(int** mat, int matSize, int* matColSize, int** target, int targetSize, int* targetColSize){
    int i, j, k, t, flag;

    k = 4;
    while(k > 0)
    {
        flag = 0;
        for (i = 0; i < matSize; ++i)
        {
            for (j = 0; j < matColSize[i]; ++j)
            {
                if (mat[i][j] != target[i][j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }
        if (flag == 0)
            break;
        for (i = 0; i < matSize; ++i)
        {
            for (j = 0; j < matColSize[i]/2; ++j)
            {
                int t = mat[j][i];
                mat[j][i] = mat[matSize-1-j][i];
                mat[matSize-1-j][i] = t;
            }
        }
        for (i = 0; i < matSize; ++i)
        {
            for (j = 0; j < i; ++j)
            {
                t = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = t;
            }
        }
        k--;
    }
    if (flag == 0)
        return true;
    else
        return false;
}