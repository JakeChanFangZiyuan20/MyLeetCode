# LeetCode-59-Spiral Matrix II-螺旋矩阵 II

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/59.png)

## 综述：  
\+ 这题和[LeetCode54.螺旋矩阵](https://leetcode-cn.com/problems/spiral-matrix/)极为相似，只是本题是往矩阵里填东西。  

## Code
```
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>result(n, vector<int>(n, 0));
        int count = 1;
        string direction = "right";
        queue<pair<int, int>>pointsQue;
        pointsQue.push(pair<int, int>(0, 0));
        while(!pointsQue.empty()){
            pair<int, int>curPoint = pointsQue.front();
            pointsQue.pop();
            int i = curPoint.first, j = curPoint.second;
            result[i][j] = count++;
            if(direction == "right") {
                if(j + 1 < n && result[i][j + 1] == 0){
                    pointsQue.push(pair<int, int>(i, j + 1));
                } else if(i + 1 < n && result[i + 1][j] == 0){
                    pointsQue.push(pair<int, int>(i + 1, j));
                    direction = "down";
                }
                continue; 
            }
            if(direction == "down") {
                if(i + 1 < n && result[i + 1][j] == 0){
                    pointsQue.push(pair<int, int>(i + 1, j));
                } else if( j - 1 >= 0 && result[i][j - 1] == 0){
                    pointsQue.push(pair<int, int>(i, j - 1));
                    direction = "left";
                }
                continue;
            }
            if(direction == "left") {
                if(j - 1 >= 0 && result[i][j - 1] == 0){
                    pointsQue.push(pair<int, int>(i, j - 1));
                } else if( i - 1 >= 0 && result[i - 1][j] == 0){
                    pointsQue.push(pair<int, int>(i - 1, j));
                    direction = "up";
                }
                continue;
            }
            if(direction == "up") {
                if(i - 1 >= 0 && result[i - 1][j] == 0){
                    pointsQue.push(pair<int, int>(i - 1, j));
                } else if( j + 1 < n && result[i][j + 1] == 0){
                    pointsQue.push(pair<int, int>(i, j + 1));
                    direction = "right";
                }
                continue;
            }
        }
        return result;
    }
};
```


## 复杂度分析
空间复杂度O(n<sup>2</sup>)  
时间复杂度O(n<sup>2</sup>)

