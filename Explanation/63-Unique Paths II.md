# LeetCode-63-Unique Paths II-不同路径 II

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/63.png)

## 综述：  
\+ 该题方法同[LeetCode62.不同路径](https://leetcode-cn.com/problems/unique-paths/)大致相同，区别在于多了障碍物，那么我们可以先将第一行和第一列弄好。  
\+ 遍历第一行，若为 0 时则赋值 1，若为 1 时则赋值 0。第一列的赋值方法相同。  
\+ 然后从位置（1，1）开始从左到右，从上到下。跟 LeetCode62.不同路径 中一样。  
\+ 但这里如果所有变量采用 int 型会出现数值超范围，所以最好使用 long 建立一个matrix，matrix 中数值同所给矩阵相同，然后进行相加运算时，也是用 long 型变量。  

## Code
```
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // m 行，n 列
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(m == 0 && n == 0 || obstacleGrid[0][0] == 1) return 0;
        
        vector<vector<long>>matrix(m, vector<long>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    matrix[i][j] = 1;
                }
            }
        }

        // 第一行更改
        for(int i = 0; i < n; i++){
            if(matrix[0][i] == 1){
                for(int j = i; j < n; j++){
                    matrix[0][j] = 0;
                }
                break;
            } else{
                matrix[0][i] = 1;
            }
        }

        // 第一列更改m
        for(int i = 1; i < m; i++){
            if(matrix[i][0] == 1){
                for(int j = i; j < m; j++){
                    matrix[j][0] = 0;
                }
                break;
            } else{
                matrix[i][0] = 1;
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 1){
                    matrix[i][j] = 0;
                    continue;
                }

                long up = matrix[i - 1][j], left = matrix[i][j - 1];
                matrix[i][j] = up + left;
            }
        }
        return matrix[m - 1][n - 1];
        //return 0;
    }
};
```


## 复杂度分析
空间复杂度O(mn)  
时间复杂度O(mn)

