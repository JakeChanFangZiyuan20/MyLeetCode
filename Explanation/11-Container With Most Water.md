# LeetCode-11-Container With Most Water-盛最多水的容器

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/11.png)

## 综述：  
\+ 使用双指针，指向一头一尾，按照短的边计算面积，然后更新最大面积值，然后短的边向右（l）或向左（r）移。  
\+ 该题一开始想到上方所描述的方法，但对于height[l] = height[r]会是怎么情况时产生疑问，参考了讨论区的说法。
\+ 在height[l] = height[r]的情况下，l，r之间如果存在有height[x]（l < x < r）都高于height[l] 和 height[r]才会存在面积更大的可能，但无论l先移还是r先移，最终都会经过能够形成最大面积的情况。  

## Code
```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxS = 0;
        while(i < j){
            int curS = min(height[i], height[j]) * (j - i);
            if(curS > maxS) maxS = curS;
            if(height[i] < height[j]) i++;
            else j--;
        }
        return maxS;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

