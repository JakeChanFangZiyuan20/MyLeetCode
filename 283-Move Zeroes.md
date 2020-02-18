# LeetCode-283-Move Zeroes-移动零

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/283.png)

## 综述：  
\+ 本题使用双指针，设置快慢指针，慢指针 i，快指针 j。开始遍历前，i = 0，j = i + 1。进入遍历时，如果 nums[i] != 0，则 i++，j++。如果 nums[i] == 0，则 j 前进直到 nums[j] != 0，此时 swap(nums[i], nums[j])，并 i++，j++。

## Code
```
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0) return ;
        if(nums.size() == 1) return ;

        int n = nums.size();
        for(int i = 0, j = i + 1; j < n; i++, j++){
            if(nums[i] != 0) continue;
            else{
                for(j; j < n; j++){
                    if(nums[j] != 0){
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

