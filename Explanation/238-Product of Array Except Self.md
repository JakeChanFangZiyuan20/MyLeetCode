# LeetCode-238-Product of Array Except Self-除自身以外数组的乘积

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/238.png)

## 综述：  
\+ 这里分两个情况：  
\+ 第一种情况：包含 0。先扫描一遍数组，统计 0 的个数，当大于等于 2，直接返回只有 0 的 output 结果数组。若只有一个 0，则将除 0 外的其他元素相乘，赋值到 0 位置对应在 output 数组中。  
\+ 第二种情况：不包含 0 。对于第一个元素，对应 output 内值是其后面元素全部相乘，累乘到 last 中，从第二个元素开始，则 last = output[i] = last / nums[i] * nums[i - 1]。

## Code
```
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), last = 1;
        vector<int>output(n, 0);

        int zero_pos = -1, zero_count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                if(zero_pos == -1) zero_pos = i;
                zero_count++;
                if(zero_count >= 2){
                    return output;
                }
            }
        }
        if(zero_pos != -1){
            for(int i = 0; i < n; i++){
                if(i == zero_pos) continue;
                last *= nums[i];
            }
            output[zero_pos] = last;
            return output;
        }

        for(int i = 0; i < n; i++){
            if(i == 0){
                for(int j = 1; j < n; j++){
                    last *= nums[j];
                }
                output[i] = last;
            } else{
                last = output[i] = last / nums[i] * nums[i - 1];
            }
        }
        return output;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

