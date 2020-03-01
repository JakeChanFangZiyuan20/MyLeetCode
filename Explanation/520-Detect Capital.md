# LeetCode-520-Detect Capital-检测大写字母

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/520.png)

## 综述：  
\+ 按要求写代码。

## Code
```
class Solution {
public:
    bool detectCapitalUse(string word) {
        int strLen = word.size();
        if(strLen == 1) return true;

        short flag = 0;
        for(int i = 0; i < strLen; i++){
            if(i == 0){
                if('a' <= word[i] && word[i] <= 'z'){
                    flag = 2;
                } else if('A' <= word[i] && word[i] <= 'Z'){
                    flag = 11;
                    if('a' <= word[i + 1] && word[i + 1] <= 'z'){
                        flag = 12;
                    }
                }
            } else{
                if(flag == 11 && (word[i] >= 'a' && word[i] <= 'z')){
                    return false;
                } else if(flag == 12 && (word[i] >= 'A' && word[i] <= 'Z')){
                    return false;
                } else if(flag == 2 && (word[i] >= 'A' && word[i] <= 'Z')){
                    return false;
                }
            }
        }

        return true;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

