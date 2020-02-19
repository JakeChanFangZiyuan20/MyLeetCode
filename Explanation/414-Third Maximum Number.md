# LeetCode-414-Third Maximum Number-第三大的数

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/414.png)

## 综述：  
\+ 方法一：使用函数先将数组排序，但复杂度为O(nlogn)，不符合题意  
\+ 先将所给数组排序，然后从后往前遍历。将最后一个元素设为最小值，然后设置一个计数器（初始值为 1 ），再从倒数第二个数开始遍历，若发现当前元素小于最小值，更新最小值并将计数器 +1 ，计数器每加一次判断是否为 3，若是则返回当前元素。若没有第三大的数，则最终返回最后一个元素（因为已排序）。

\+ 方法二：  
\+ 设置第一、第二、第三大，开始时可将第一大设置为数组一个元素，然后第二第三大设置为 LONG_MIN 。然后从数组第二个元素开始遍历，如大于第一大，则将第二大移至第三大，第一大移至第二大，第一大更新为此时数值。如大于第二大，则将第二大移至第三大，第二大更新为此时数值。如大于第三大，直接更新第三大。  
\+ 遍历结束后，判断第三大是否仍为 LONG_MIN ，若是则没有第三大，直接返回第一大，若否，则返回第三大。  

## Code-1
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

## Code-3
```
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size(), max1 = nums[0];
        long max2, max3;
        max2 = max3 = LONG_MIN;
        for(int i = 0; i < n; i++){
            if(nums[i] == max1 || nums[i] == max2 || nums[i] == max3) continue;
            if(nums[i] > max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            } else if(nums[i] > max2){
                max3 = max2;
                max2 = nums[i];
            } else if(nums[i] > max3){
                max3 = nums[i];
            }
        }
        if(max3 == LONG_MIN) return max1;
        return (int)max3;
    }
};
```

## 复杂度分析
方法一：  
空间复杂度O(1)  
时间复杂度O(nlogn)  

方法二：  
空间复杂度O(1)  
时间复杂度O(n)  

