# LeetCode-42-Trapping Rain Water-接雨水

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/42.png)





## 综述：  
\+ 该题一开始想到栈，然后却以栈顶为左边界去想，若当前比栈顶小则入栈，结果想了许久最终参考。  
\+ 以每个柱形图为凹处最低点，则需要寻找左右第一个高于其的柱形图。所以维护一个栈（存储下标），栈顶为凹处最低点，遍历数组时，若当前（相当于右边界）小于栈顶则入栈，高于则可认为栈顶可作为最低点装水，则将栈顶弹出，此时栈顶为左边界，计算装水量。重复直至栈顶大于当前。  
\+ 直观上相当于一层一层加水。实际代码运行有偏差。  

## Code
```
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0 || height.size() == 1) return 0;
        int S = 0;
        stack<int>heightStack;
        for(int i = 0; i < height.size(); i++){
            while(heightStack.size() && height[i] > height[heightStack.top()]){
                int top = heightStack.top();
                heightStack.pop();
                if(heightStack.empty()) break;
                int dis = i - heightStack.top() - 1;
                int curS = dis * (min(height[i], height[heightStack.top()]) - height[top]);
                S += curS;
            }
            heightStack.push(i);
        }
        return S;
    }
};
```

## 复杂度分析
时间复杂度O(n)  
空间复杂度O(n)
