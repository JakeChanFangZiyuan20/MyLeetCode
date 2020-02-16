# LeetCode-154-Find Minimum in Rotated Sorted Array II-寻找旋转排序数组中的最小值 II

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/154.png)

## 综述：  
\+ 本题解法在[LeetCode81.搜索旋转排序数组 II](https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/)基础之上，可参考[Search in Rotated Sorted Array II](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/Explanation/81-Search%20in%20Rotated%20Sorted%20Array%20II.md)

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
            if(nums[middle] == nums[left]){
                left++;
            } else if(nums[middle] <= nums[right]) right = middle;
            else left = middle;

            if(left + 1 == right) break;
        }
        
        return min(nums[left], nums[right]);
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(logn)

