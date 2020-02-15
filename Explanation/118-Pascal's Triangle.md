# LeetCode-118-Pascal's Triangle-杨辉三角

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/118.png)

## 综述：  
\+ 按要求写代码。  

## Code
```
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return vector<vector<int>>();

        vector<vector<int>>result;

        for(int i = 1; i <= numRows; i++){
            vector<int>newRow(i, 1);
            if(i > 2){
                for(int j = 1; j < newRow.size() - 1; j++){
                    newRow[j] = (*(result.end() - 1))[j] + (*(result.end() - 1))[j - 1];
                }
            }
            result.push_back(newRow);
        }

        return result;
    }
};
```


## 复杂度分析
空间复杂度O(n<sup>2</sup>)  
时间复杂度O(n<sup>2</sup>)

