# LeetCode-66-Plus One-加一

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/66.png)

## 综述：  
\+ 该题注意进位即可。

## Code
```
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0) return vector<int>();

        if(digits[0] == 0) return vector<int>(1, 1);
        
        int flag = 0, n = digits.size();
        int curSum = digits[n - 1] + 1 + flag;
        digits[n - 1] = curSum % 10;
        flag = curSum / 10;
        for(int i = n - 2; i >= 0; i--){
            if(flag == 0) break;
            curSum = digits[i] + flag;
            digits[i] = curSum % 10;
            flag = curSum / 10;
        }
        if(flag){
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

