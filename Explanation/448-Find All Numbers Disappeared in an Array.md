# LeetCode-448-Find All Numbers Disappeared in an Array-找到所有数组中消失的数字

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/448.png)

## 综述：  
\+ 该题参考题解。  
\+ 从左向右遍历数组，当前元素表示在该数组中出现过的值，所以可以以该数值 -1 后为下标，然后标记。即 nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1])。标记完后，再次遍历数组，找到大于 0 的数值，该下标 +1 便是答案之一。  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/448-1.png)
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/448-2.png)
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/448-3.png)
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/448-4.png)
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/448-5.png)
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/448-6.png)
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/448-7.png)
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/448-8.png)
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/448-9.png)
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/448-10.png)

## Code
```
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return nums;
        for(int i = 0; i < n; i++){
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        }
        vector<int>result;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                result.push_back(i + 1);
            }
        }
        return result;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

