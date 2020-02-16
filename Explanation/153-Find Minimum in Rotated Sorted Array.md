# LeetCode-153-Find Minimum in Rotated Sorted Array-寻找旋转排序数组中的最小值

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/153.png)

## 综述：  
\+ 本题在[LeetCode33.搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)的基础之上，使用二分，参考解法[Search in Rotated Sorted Array](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/Explanation/33-Search%20in%20Rotated%20Sorted%20Array.md)，区别在于只需找到最小值。

## Code
```
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] < nums[n - 1]) return nums[0];
        int left = 0, right = n - 1;
        while(left < right){
            int middle = (left + right) / 2;

            if(nums[middle] <= nums[right]) right = middle;
            else left = middle;

            if(left + 1 == right) break;
        }

        return nums[right];
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(logn)

