# LeetCode-169-Majority Element-多数元素

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/169.png)

## 综述：  
\+ 先将数组排序，然后使用一个额外数组记录每个元素的出现次数，如图：  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/169-1.png)  
\+ 每计算一次出现次数，则检查是否大于 n / 2。

## Code
```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>count(n, 1);
        int result = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1]){
                count[i] = count[i - 1] + 1;
                if(count[i] > n / 2){
                    result = nums[i];
                    break;
                }
            } 
        }
        return result;
    }
};
```


## 复杂度分析
空间复杂度O(n)  
时间复杂度O(n)

