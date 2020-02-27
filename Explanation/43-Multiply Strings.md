# LeetCode-43-Multiply Strings-字符串相乘

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/43.png)

## 综述：  
\+ 方法一：  
\+ 模拟竖式相乘，如果用 num1 * num2 ，则对于 num2 ，从 num2 的第一位开始乘 num1 ，获得的结果在后面加 0，然后 num2 的第二位开始乘 num1 ，并加上刚刚 num2 的第一位乘 num1 的结果，重复。如果当前是 num2 的最后一位，则直接加上上一次乘的结果就行。  


## Code
```
class Solution {
public:
    string multiply(string num1, string num2) {
        int str1Size = num1.size(), str2Size = num2.size();
        if(str1Size == 0 || str2Size == 0) return "";
        if(num1[0] == '0' || num2[0] == '0') return "0";

        string result(""), curResult;
        for(int i = 0; i < str2Size; i++){
            curResult = OneMultiBig(num2[i] - 48, num1);
            result = add(curResult, result);
            if(i < str2Size - 1) result += "0";
        }

        return result;
    }

    string OneMultiBig(int one, string big){
        if(one == 0) return "0";

        int flag = 0, strSize = big.size();
        string result("");
        for(int i = strSize - 1; i >= 0; i--){
            int tempRes = one * (big[i] - 48) + flag;
            result = to_string(tempRes % 10) + result;
            flag = tempRes / 10;
        }
        if(flag) result = to_string(flag) + result;
        return result;
    }

    string add(string num1, string num2){
        if(num1[0] == '0') return num2;
        if(num2[0] == '0') return num1;

        if(num1.size() < num2.size()) swap(num1, num2);
        int str1Size = num1.size(), str2Size = num2.size();
        int zeros = str1Size - str2Size;
        num2 = string(zeros, '0') + num2;

        string result("");
        int flag = 0;
        for(int i = str1Size - 1; i >= 0; i--){
            int tempRes = num1[i] - 48 + num2[i] - 48 + flag;
            result = to_string(tempRes % 10) + result;
            flag = tempRes / 10;
        }
        if(flag) result = to_string(flag) + result;
        return result;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(mn)  

