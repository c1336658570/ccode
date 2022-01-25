/*
坐标型
给定一个二维矩阵, 每一个格子可能是一堵墙 W,或者 一个敌人 E 或者空 0 (数字 '0'), 
返回你可以用一个炸弹杀死的最大敌人数. 炸弹会杀死所有在同一行和同一列没有墙阻隔的敌人。
由于墙比较坚固，所以墙不会被摧毁.你只能在空的地方放置炸弹.

样例1
输入:
grid =[
     "0E00",
     "E0WE",
     "0E00"
]
输出: 3
解释:
把炸弹放在 (1,1) 能杀3个敌人
样例2
输入:
grid =[
     "0E00",
     "EEWE",
     "0E00"
]
输出: 2
解释:
P把炸弹放在 (0,0) 或 (0,3) 或 (2,0) 或 (2,3) 能杀2个敌人
*/

# include <stdio.h>

int maxKilledEnemies(char **grid, int size, int *colsize) {
     // write your code here
     if (size == 0 || colsize[0] == 0 || grid == NULL)
          return 0;

     int m = size;
     int n = colsize[0];
     int f[m][n];
     int res[m][n];
     int i, j;
     for (i = 0; i < m; ++i)
     {
          for (j = 0; j < n; ++j)
          {
               //res代表有多少敌人被炸死
               res[i][j] = 0;
          }
     }
     //up
     for (i = 0; i < m; ++i)
     {
          for (j = 0; j < n; ++j)
          {
               if (grid[i][j] == 'W')
               {
               f[i][j] = 0;
               }
               else
               {
               f[i][j] = 0;
               if (grid[i][j] == 'E')
               {
                    f[i][j] = 1;
               }
               if (i > 0)
               {
                    f[i][j] += f[i-1][j];
               }
               }
               res[i][j] += f[i][j];
          }
     }
     //down
     for (i = m-1; i >= 0; --i)
     {
          for (j = 0; j < n; ++j)
          {
               if (grid[i][j] == 'W')
               {
               f[i][j] = 0;
               }
               else
               {
               f[i][j] = 0;
               if (grid[i][j] == 'E')
               {
                    f[i][j] = 1;
               }
               if (i < m-1)
               {
                    f[i][j] += f[i+1][j];
               }
               }
               res[i][j] += f[i][j];
          }
     }
     //left
     for (i = 0; i < m; ++i)
     {
          for (j = 0; j < n; ++j)
          {
               if (grid[i][j] == 'W')
               {
               f[i][j] = 0;
               }
               else
               {
               f[i][j] = 0;
               if (grid[i][j] == 'E')
               {
                    f[i][j] = 1;
               }
               if (j > 0)
               {
                    f[i][j] += f[i][j-1];
               }
               }
               res[i][j] += f[i][j];
          }
     }
     //right
     for (i = 0; i < m; ++i)
     {
          for (j = n-1; j >= 0; --j)
          {
               if (grid[i][j] == 'W')
               {
               f[i][j] = 0;
               }
               else
               {
               f[i][j] = 0;
               if (grid[i][j] == 'E')
               {
                    f[i][j] = 1;
               }
               if (j < n-1)
               {
                    f[i][j] += f[i][j+1];
               }
               }
               res[i][j] += f[i][j];
          }
     }
     int result = 0;
     for (i = 0; i < m; ++i)
     {
          for (j = 0; j < n; ++j)
          {
               if (grid[i][j] == '0')
               {
                    if (res[i][j] > result)
                    {
                         result = res[i][j];
                    }
               }
          }
     }
     return result;
}