# LeetCode-62-Unique Paths-不同路径

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/62.png)

## 综述：  
\+ 该题参考了题解。  
\+ 使用动态规划方法，对于位置（i，j），ways[i][j] 表示从开始点到该位置的方法数，则ways[i][j] = ways[i - 1][j] + ways[i][j - 1]。  
\+ 若 i = 0 或 j = 0，则 ways[i][j] = 1。

## Code
```
class Solution {
public:
    int uniquePaths(int m, int n) {
        // n 行，m 列
        if(n == 0 && m == 0) return 0;
        if(n == 1 || m == 1) return 1;

        vector<vector<int>>matrix(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0){
                    matrix[i][j] = 1;
                    continue;
                }
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            }
        }
        return matrix[n - 1][m - 1];
    }
};
```


## 复杂度分析
空间复杂度O(mn)  
时间复杂度O(mn)

