# LeetCode-84-Largest Rectangle in Histogram-柱状图中最大的矩形

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/84.png)





## 综述：  
\+ 该题参考了题解：  
\+ 使用单调栈，栈中存储数组元素的下标，栈先压入-1。  
\+ 遍历数组，当栈为空时（hs.top() == -1）或者当前数组元素大于栈顶时压入下标。  
\+ 遇到当前数组元素小于栈顶时将栈顶元素弹出，并计算面积，重复直到栈空或栈顶元素对应值大于当前对应。  
\+ 遍历完后，若栈不为空，则从栈顶开始弹出计算面积。

## Code
```
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0) return 0;
        int maxS = 0;
        stack<int>hs;
        hs.push(-1);
        for(int i = 0; i < heights.size(); i++){
            while(hs.top() != -1 && heights[hs.top()] > heights[i]){
                int top = hs.top();
                hs.pop();
                maxS = max(maxS, heights[top] * (i - hs.top() - 1)); // 面积
            }
            hs.push(i);
        }
        while(hs.top() != -1){
            int top = hs.top();
            hs.pop();
            maxS = max(maxS, (int)(heights[top] * (heights.size() - hs.top() - 1))); //面积
        }
        return maxS;
    }
};
```

## 复杂度分析
时间复杂度O(n)  
空间复杂度O(n)
