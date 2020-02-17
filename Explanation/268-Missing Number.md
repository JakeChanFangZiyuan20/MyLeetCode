# LeetCode-268-Missing Number-缺失数字

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/268.png)

## 综述：  
\+ 方法一：  
\+ 将数组排序。若排序后 nums[n - 1] == n - 1，证明只是确实 n，则直接返回 n。若排序后 nums[n - 1] != n - 1，则遍历元素的时候使用下标比较当前元素，若nums[i] != i，那么返回 i。  

\+ 方法二：数学  
\+ 使用 n * (n + 1) / 2 可求得 n 个数值和，减去当前所给数组总和就得到缺失数字。  
\+ 直接使用求和公式存在溢出风险，需要可通过加一个，减去一个来解决。  

\+ 方法三：位运算  
\+ 这里使用异或运算，异或运算满足结合律，并且当两个相同数值进行异或运算时结果为 0，而 0 与任何数 a 异或运算等于 a（除 0 外），那么用 0 到 n 同所给数组进行异或运算结果就会得到缺失的数字。

## Code-1
```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int  n = nums.size(), result;
        if(nums[n - 1] == n - 1) return n;
        for(int i = 0; i < n; i++){
            if(nums[i] != i){
                result = i;
                break;
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
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i = 1; i <= n; i++){
            sum += i;
            sum -= nums[i - 1];
        }
        return sum;
    }
};
```

## Code-3
```
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), XOR = n;
        for(int i = 0; i < n; i++){
            XOR ^= i;
        }
        for(int i = 0; i < n; i++){
            XOR ^= nums[i];
        }
        return XOR;
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

方法三：  
空间复杂度O(1)  
时间复杂度O(n)  
