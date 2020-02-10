# LeetCode-31-Next Permutation-下一个排列

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/31.png)

## 综述：  
\+ 从后往前遍历，若当前数值大于前一个数值则证明存在下一个更大字典序的排列，则再次从后开始到当前数值位置找到大于当前位置钱一个位置数值的数，然后互相交换，然后从当前位置开始到最后进行升序排序。  

## Code
```
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return ;
        int flag = 0;
        for(int i = n - 1; i > 0; i--){
            if(nums[i] > nums[i - 1]){
                for(int j = n - 1; j > i - 1; j--){
                    if(nums[j] > nums[i - 1]){
                        swap(nums[j], nums[i - 1]);
                        sort(nums.begin() + i, nums.end());
                        break;
                    }
                }
                flag = 1;
                break;
            }
        }
        if(flag == 0) sort(nums.begin(), nums.end());
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

