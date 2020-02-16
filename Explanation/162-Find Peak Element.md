# LeetCode-162-Find Peak Element-寻找峰值

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/162.png)

## 综述：  
\+ 该题参考了题解。  
\+ 一开始想到顺序遍历，但题目要求O(logn)，说明要使用二分，但二分在数组有序情况下使用才有效果，所以一直寻找通过有序来解题，最后还是摸不着头发。  
\+ 通过理解题目所给 nums[-1] = nums[n] = -∞ 以及峰值的含义，直接二分在本本题上可行，因为如果 nums[middle] < nums[middle + 1]，则证明中点后呈上升趋势以及右半部分肯定存在峰值，若nums[middle] < nums[middle + 1]，峰值则在左方，由于只需寻找到其中一个峰值，所以按照上述是可以找到其一峰值。

## Code
```
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), left = 0, right = n - 1;
        if(n == 1) return 0;
        if(n == 2) return nums[0] > nums[1] ? 0 : 1;
        while(left < right){
            int middle = (left + right) / 2;

            if(nums[middle] < nums[middle + 1]) left = middle;
            else if(nums[middle] > nums[middle - 1]){
                return middle;
            } else{
                right = middle;
            }

            if(left + 1 == right){
                if(left == 0) return left;
                if(right == n - 1) return n - 1;
            }
        }

        return left;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(logn)

