# LeetCode-238-Product of Array Except Self-除自身以外数组的乘积

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/238.png)

## 综述：  
\+ 方法一：包含除法  
\+ 这里分两个情况：  
\+ 第一种情况：包含 0。先扫描一遍数组，统计 0 的个数，当大于等于 2，直接返回只有 0 的 output 结果数组。若只有一个 0，则将除 0 外的其他元素相乘，赋值到 0 位置对应在 output 数组中。  
\+ 第二种情况：不包含 0 。对于第一个元素，对应 output 内值是其后面元素全部相乘，累乘到 last 中，从第二个元素开始，则 last = output[i] = last / nums[i] * nums[i - 1]。

\+ 方法二：不包含除法，左右乘积列法  
\+ 对于每一个元素，其 output 对应值为 其左部分乘积 * 其右部分乘积。那么可以构造左乘积数列和右乘积数列，然后两数列对应相乘构成 output。  
\+ 下图为左乘积数列：  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/238-1.png)
\+ 下图为右乘积数列：  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/238-2.png)
\+ 结果 output，上方两个数列对应位置数值相乘。  
\+ 为了保证空间复杂度 O(1)，则可直接在 output 数组上操作。构造左数列从左到右。然后使用一个临时变量来从右到左，计算当下位置右数列数值，然后乘当下 output 中的数值，获得当前 output 位置的真正数值。  

## Code-1
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

## Code-2
```
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>output(n, 1);
        // 构造左乘积序列
        for(int i = 1; i < n; i++){
            output[i] = nums[i - 1] * output[i - 1];
        }

        int last = 1;
        for(int i = n - 2; i >= 0; i--){
            last *= nums[i + 1];
            output[i] *= last; 
        }
        
        return output;
    }
};
```


## 复杂度分析
方法一：  
空间复杂度O(1)  
时间复杂度O(n)  

方法二：  
空间复杂度O(1)  
时间复杂度O(n)  

