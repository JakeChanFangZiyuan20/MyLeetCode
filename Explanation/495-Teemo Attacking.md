# LeetCode-495-Teemo Attacking-提莫攻击

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/495.png)

## 综述：  
\+ 本题解法相对基本，可从第二次攻击开始加时间，所以总时间直接初始化为单词攻击持续时间。  
\+ 从第二次开始，如果当前攻击开始时间在上一次攻击结束时间之后，则总时间直接加上持续时间，若在上一次攻击结束时间之前则在总时间加上持续时间之后减去重合的时间（上一次攻击结束时间减当前攻击开始时间）。  

## Code
```
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        if(n == 0 || duration == 0) return 0;

        int totalTime = duration;
        for(int i = 1; i < n; i++){
            if((timeSeries[i] - 1) - (timeSeries[i - 1] - 1 + duration) >= 0){ 
                totalTime += duration;
            } else{
                totalTime += 
                    (duration - ((timeSeries[i - 1] - 1 + duration) - (timeSeries[i] - 1)));
            }
        }
        return totalTime;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

