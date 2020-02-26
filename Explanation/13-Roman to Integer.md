# LeetCode-13-Roman to Integer-罗马数字转整数

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/13.png)

## 综述：  
\+ 按要求写代码。  

## Code
```
class Solution {
public:
    int romanToInt(string s) {
        int n = s.size(), result = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == 'I') result += 1;
            if(s[i] == 'V'){
                result += 5;
                if(i > 0 && s[i - 1] == 'I'){
                    result -= 1;
                    i--;
                }
            }
            if(s[i] == 'X'){
                result += 10;
                if(i > 0 && s[i - 1] == 'I'){
                    result -= 1;
                    i--;
                }
            }
            if(s[i] == 'L'){
                result += 50;
                if(i > 0 && s[i - 1] == 'X'){
                    result -= 10;
                    i--;
                }
            }
            if(s[i] == 'C'){
                result += 100;
                if(i > 0 && s[i - 1] == 'X'){
                    result -= 10;
                    i--;
                }
            }
            if(s[i] == 'D'){
                result += 500;
                if(i > 0 && s[i - 1] == 'C'){
                    result -= 100;
                    i--;
                }
            }
            if(s[i] == 'M'){
                result += 1000;
                if(i > 0 && s[i - 1] == 'C'){
                    result -= 100;
                    i--;
                }
            }
        }
        return result;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

