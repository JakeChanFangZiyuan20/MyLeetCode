# LeetCode-119-Pascal's Triangle II-杨辉三角 II

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/119.png)

## 综述：  
\+ 该题使用空间复杂度 O(k) 来求解。  
\+ 下图为过程：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/119-1.png)

## Code
```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return vector<int>(1, 1);

        vector<int>result(rowIndex + 1, 1);
        if(result.size() > 2){
            for(int i = 3; i <= rowIndex + 1; i++){
                for(int j = i - 2; j > 0; j--){
                    result[j] += result[j - 1]; 
                }
            }
        }

        return result;
    }
};
```


## 复杂度分析
空间复杂度O(k)  
时间复杂度O(k<sup>2</sup>)

