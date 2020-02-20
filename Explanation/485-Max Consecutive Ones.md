# LeetCode-485-Max Consecutive Ones-最大连续1的个数

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/485.png)

## 综述：  
\+ 从左到右遍历数组，当前为 1，则从当前开始向右直到不为 1，记录两个位置（i，j），i - j 则为这一段连续 1 的长，然后和最大长比较。  

## Code
```
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0] == 1 ? 1 : 0;

        int maxLength = INT_MIN;
        int i, j;
        for(i = 0; i < n; ){
            if(nums[i] == 1){
                j = i;
                while(j < n && nums[j] == nums[i]){
                    j++;
                }
                maxLength = max(maxLength, j - i);
                i = j;
            }else{
                i++;
            }
        }
        if(maxLength == INT_MIN) return 0;
        maxLength = max(maxLength, j - i);
        return maxLength;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

