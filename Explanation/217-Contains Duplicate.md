# LeetCode-217-Contains Duplicate-存在重复元素

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/217.png)

## 综述：  
\+ 

## Code
```
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return false;

        sort(nums.begin(), nums.end());

        bool result = false;
        int n = nums. size();
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1]){
                result = true;
                break;
            }
        }

        return result;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

