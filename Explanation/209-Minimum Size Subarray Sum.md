# LeetCode-209-Minimum Size Subarray Sum-长度最小的子数组

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/209.png)

## 综述：  
\+ 说明：所有数都为正整数，说明前缀和矩阵单调递增。
\+ 先构造前缀和数组，如果 nums[0] <= s ，则返回 1 。如果nums[n - 1] < s ，则返回 0 。  
\+ 先设置 result 为 INT_MAX ， 从后往前遍历前缀和数组：如果 nums[i] == s ，则 result = min(result, i + 1)，并 break；对于 nums[i] > s 下的位置，找到首个大于 nums[i] - s 的数值的位置 curPos ，然后 result = min(result, i - curPos + 1)，因为对于 curPos 前的数值，用 nums[i] 减去肯定大于 s ，在保证子序列长度最小的情况下，curPos 到 i 的子序列长度最小。  

## Code
```
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1){
            if(nums[0] == s) return 1;
            else return 0;
        }

        if(s <= nums[0]) return 1;

        int n = nums.size();
        for(int i = 1; i < n; i++){
            nums[i] += nums[i - 1];
        }

        if(nums[n - 1] < s) return 0;

        int result = INT_MAX;
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] == s){
                result = min(result, i + 1);
                break;
            }
            if(nums[i] < s){
                break;
            }
            vector<int>::iterator iter = upper_bound(nums.begin(), nums.end(), nums[i] - s);
            if(iter != nums.end()){
                result = min(result, i - (int)(iter - nums.begin()) + 1);
            }
        }

        return result;
    }
};
```


## 复杂度分析
空间复杂度O(n)  
时间复杂度O(nlogn)

