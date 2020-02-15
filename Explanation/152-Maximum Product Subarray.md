# LeetCode-152-Maximum Product Subarray-乘积最大子序列

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/152.png)

## 综述：  
\+ 该题参考了题解。  
\+ 使用动态规划方法，这里有个难点在于乘法存在负负得正，存在当前为负数，然后前面相乘最小值也为负数，相乘会得到一个很大的值，所以在设立记录当前最大值和总最大值之外，还需要设立当前最小值，那么：  
\+ dpMax[i] = max(nums[i], max(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]))  
\+ dpMin[i] = min(nums[i], min(dpMax[i - 1] * nums[i], dpMin[i - 1] * nums[i]))  
\+ maxResult = max(maxResult, dpMax[i])

## Code
```
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        int n = nums.size(), maxResult = nums[0], curMax = nums[0], curMin = nums[0];
        for(int i = 1; i < n; i++){
            int tempMax = max(nums[i], max(curMax * nums[i], curMin * nums[i]));
            int tempMin = min(nums[i], min(curMax * nums[i], curMin * nums[i]));
            curMax = tempMax; curMin = tempMin;
            maxResult = max(maxResult, curMax);
        }

        return maxResult;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

