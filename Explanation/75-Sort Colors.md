# LeetCode-75-Sort Colors-颜色分类

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/75.png)

## 综述：  
\+ 这里一趟扫描即可实现。  
\+ 使用双指针，开始时分别指向头尾，两指针为 left 和 right。  
\+ left 和 right 分别为下一个 0 和 2 插入的位置。  
\+ 使用 i 从左向右开始扫描，若当前数值为 1 则 i++ 并 continue。  
\+ 若当前数值为 0，则swap(nums[i], nums[left++])，以及 i++ 并 continue。因为从前面换过来的值只可能是 0 或 1，则 i 可以 +1。  
\+ 若当前数值为 2，则swap(nums[i], nums[right--])，以及 continue。因为从后面换过来的值有可能是 0 或 1，则 i 不需要 +1。  
\+ 当 i > right 时，结束遍历，因为 right后面全是相同的数，且为当前所给数组中最大的数。

## Code
```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() == 0) return ;

        int n = nums.size(), left = 0, right = n - 1;
        for(int i = 0; i <= right; ){
            if(nums[i] == 1){
                i++;
                continue;
            }
            if(nums[i] == 0){
                swap(nums[i], nums[left++]);
                i++;
                continue;
            }
            if(nums[i] == 2){
                swap(nums[i], nums[right--]);
            }
        }
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

