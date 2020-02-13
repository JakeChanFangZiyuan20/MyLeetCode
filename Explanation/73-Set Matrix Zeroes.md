# LeetCode-73-Set Matrix Zeroes-矩阵置零

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/73.png)

## 综述：  
\+ 从左到右，从上到下遍历二维数组，遇到 0，则使用两个 set 分别记录其行位置和列位置。  
\+ 遍历两个 set，根据行和列设置 0。

## Code
```
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return ;
        int m = matrix.size(), n = matrix[0].size();
        set<int>rowSet, colSet;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    rowSet.insert(i);
                    colSet.insert(j);
                }
            }
        }
        for(set<int>::iterator iter = rowSet.begin(); iter != rowSet.end(); iter++){
            int curRow = *iter;
            for(int j = 0; j < n; j++){
                matrix[curRow][j] = 0;
            }
        }
        for(set<int>::iterator iter = colSet.begin(); iter != colSet.end(); iter++){
            int curCol = *iter;
            for(int i = 0; i < m; i++){
                matrix[i][curCol] = 0;
            }
        }
    }
};
```


## 复杂度分析
空间复杂度O(m + n)  
时间复杂度O(mn)

