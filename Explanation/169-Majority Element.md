# LeetCode-169-Majority Element-多数元素

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/169.png)

## 综述：  
\+ 方法一：
\+ 先将数组排序，然后使用一个额外数组记录每个元素的出现次数，如图：  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/169-1.png)  
\+ 每计算一次出现次数，则检查是否大于 n / 2。  

\+ 方法二：Boyer-Moore 算法
\+ 对于所给的一个数组，需要选出多数元素，证明该元素出现次数大于 ⌊ n/2 ⌋ 。在Boyer-Moore 算法算法中，设置 candidate 和 count 变量，分别表示侯选数和侯选数个数。candidate 可以是数组中出现的任何数，可设置为 nums[0]，然后 count 设置为 1 。遍历这个数组，如果当前数和 candidate 相等，则 count + 1 ，若不等则 count - 1 ，若 count = 0，则讲当前的 nums[i] 设置为 candidate，并 count 重新赋值 1。因为总是存在一个多数元素，证明其数量大于 ⌊ n/2 ⌋ ，则其他非多数元素总个数总会小于 ⌊ n/2 ⌋，则可知用多数元素个数去抵消非多数元素个数总会大于 0，最后留下的 candidate 肯定是多数元素。

## Code-1
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

## Code-2
```
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], count = 1, n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] == candidate) count++;
            else{
                count--;
                if(count == 0){
                    candidate = nums[i];
                    count++;
                }
            }
        }
        return candidate;
    }
};
```

## 复杂度分析
方法一：  
空间复杂度O(n)  
时间复杂度O(n)  

方法二：  
空间复杂度O(1)  
时间复杂度O(n)
