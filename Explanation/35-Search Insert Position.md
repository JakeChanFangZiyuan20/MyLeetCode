# LeetCode-35-Search Insert Position-搜索插入位置

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/35.png)

## 综述：  
\+ 该题比较基础，使用二分查找。  

## Code
```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;

        int n = nums.size(), left = 0, right = n - 1;
        if(target < nums[0]) return 0;
        if(target > nums[n - 1]) return n;

        int pos;
        while(left <= right){
            if(nums[left] == target) return left;
            if(nums[right] == target) return right;

            int middle = (left + right) / 2;
            if(nums[middle] == target) return middle;

            if(nums[middle] < target) left = middle;
            else right = middle;
            
            if(left + 1 == right) break;
        }
        pos = left + 1;

        return pos;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(logn)

