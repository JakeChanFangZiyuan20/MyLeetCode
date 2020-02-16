# LeetCode-189-Rotate Array-旋转数组

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/189.png)

## 综述：  
\+ 旋转次数为 k % n。

## Code
```
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 0 || nums.size() == 1 || k == 0) return ;

        int n = nums.size(), count = k % n;
        for(int i = 1; i <= count; i++){
            nums.insert(nums.begin(), *(nums.end() - 1));
            nums.erase(nums.end() - 1);
        }
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)，n 为数组大小

