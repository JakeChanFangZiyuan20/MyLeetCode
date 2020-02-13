# LeetCode-74-Search a 2D Matrix-搜索二维矩阵

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/74.png)

## 综述：  
\+ 对于所给矩阵每一行升序，当前行的第一个数值大于前一行的最后一个数值，然后搜索是否存在target，很明显可以使用二分。  
\+ 我们可以先遍历行，锁定符合范围的行，即设当前行 i，matrix[i][0] <= target <= matrix[i][n - 1]，其中 n 为行数。  
\+ 然后在当前行使用二分算法查找。

## Code
```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;

        // m 行，n 列
        int m = matrix.size(), n = matrix[0].size();

        // 锁定行
        int row = -1;
        for(int i = 0; i < m; i++){
            if(matrix[i][0] <= target && target <= matrix[i][n - 1]){
                row = i;
                break;
            }
        }

        if(row != -1){
            int left = 0, right = n - 1;
            if(matrix[row][left] == target) return true;
            if(matrix[row][right] == target) return true;
            while(left < right){
                int middle = (left + right) / 2;
                if(matrix[row][middle] == target) return true;

                if(matrix[row][middle] < target) left = middle;
                else right = middle;

                if(matrix[row][left] == target) return true;
                if(matrix[row][right] == target) return true;

                if(left + 1 == right) break;
            }
        }

        return false;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(mlogn)

