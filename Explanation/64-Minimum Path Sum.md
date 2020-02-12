# LeetCode-64-Minimum Path Sum-最小路径和

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/64.png)

## 综述：  
\+ 该题解法同[LeetCode62.不同路径](https://leetcode-cn.com/problems/unique-paths/)类似。  
\+ 该题仍然使用动态规划方法，对于位置（i，j），从起点到达该点的最短路径为 grid[i][j] + min(grid[i - 1][j], grid[i][j - 1])。所以我们可以先处理第一行和第一列，其处理方法是：设当前（i，j），grid[i][j] = grid[i][j] + grid[i][j - 1]（第一行）或 grid[i][j] = grid[i][j] + grid[i - 1][j]（第一列）。然后从位置（1，1）开始从左到右，从上到下更新值。  

## Code
```
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // m 行，n 列
        int m = grid.size(), n = grid[0].size();
        
        if(m == 0 && n == 0) return 0;
        if(m == 1 && n == 1) return grid[0][0];
        
        // 第一行处理
        for(int i = 1; i < n; i++){
            grid[0][i] += grid[0][i - 1];
        }   
        
        // 第一列处理
        for(int i = 1; i < m; i++){
            grid[i][0] += grid[i - 1][0];
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        
        return grid[m - 1][n - 1];
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(mn)

