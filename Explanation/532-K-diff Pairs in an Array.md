# LeetCode-532-K-diff Pairs in an Array-数组中的K-diff数对

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/532.png)

## 综述：  
\+ 先将数组排序，然后从左向右遍历，当前元素为 nums[i] ，再在右方寻找 nums[i] + k，在有序数组基础上使用二分查找。当当前元素与前一个元素相等时则跳过当前元素。

## Code
```
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size(), result = 0;
        if(n == 0 || n == 1) return 0;
        if(k > 2e7) return 0;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 1; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int target = nums[i] + k;
            int left = i + 1, right = n - 1;
            while(true){
                if(nums[left] == target){
                    result++;
                    break;
                }
                if(nums[right] == target){
                    result++;
                    break;
                }
                int middle = (left + right) / 2;
                if(nums[middle] == target){
                    result++;
                    break;
                } else if(nums[middle] < target) left = middle;
                else right = middle;
                if(left + 1 == right || left == right) break;
            } 
        }

        return result;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(nlogn)

