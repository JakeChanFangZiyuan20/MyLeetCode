# LeetCode-442-Find All Duplicates in an Array-数组中重复的数据

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/442.png)

## 综述：  
\+ 本题在[LeetCode448.找到所有数组中消失的数字](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/)的基础上进行改进。  
\+ 主要不同在于以当前元素绝对值为下标时，若对应元素已经是负数，证明已经出现过，所以可以将当前元素绝对值加入到结果数组中。结果数组不需要排序。  

## Code
```
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return vector<int>();
        vector<int>result;
        for(int i = 0; i < n; i++){
            if(nums[abs(nums[i]) - 1] < 0){
                result.push_back(abs(nums[i]));
                continue;
            }
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        return result;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

