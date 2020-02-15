# LeetCode-120-Triangle-三角形最小路径和

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/120.png)

## 综述：  
\+ 先计算到达位置（i，j）的最小路径和 triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1])，然后在最后一行找到最小值返回。  

## Code
```qing
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1) return triangle[0][0];

        int n = triangle.size();
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i + 1; j++){
                if(j == 0){
                    triangle[i][j] += triangle[i - 1][j];
                } else if(j == i){
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else{
                    triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
                }
            }
        }

        int result = triangle[n - 1][0];
        for(int i = 1; i < n; i++){
            if(triangle[n - 1][i] < result) result = triangle[n - 1][i];
        }

        return result;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n<sup>2</sup>)

