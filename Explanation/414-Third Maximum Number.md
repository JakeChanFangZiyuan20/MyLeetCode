# LeetCode-414-Third Maximum Number-第三大的数

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/414.png)

## 综述：  
\+ 先将所给数组排序，然后从后往前遍历。将最后一个元素设为最小值，然后设置一个计数器（初始值为 1 ），再从倒数第二个数开始遍历，若发现当前元素小于最小值，更新最小值并将计数器 +1 ，计数器每加一次判断是否为 3，若是则返回当前元素。若没有第三大的数，则最终返回最后一个元素（因为已排序）。

## Code
```
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), minNum = nums[n - 1], count = 1;
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < minNum){
                minNum = nums[i];
                count++;
                if(count == 3) return nums[i];
            }
        }
        return nums[n - 1];
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

