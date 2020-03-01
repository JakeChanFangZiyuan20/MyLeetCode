# LeetCode-521-Longest Uncommon Subsequence I-最长特殊序列 Ⅰ

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/521.png)

## 综述：  
\+ 如果两个字符串长度相等，则判断两个字符是否相同，相同返回 -1，不同返回第一个字符串长度。  
\+ 如果两个字符串长度不等，则返回长度较大的字符串。  

## Code
```
class Solution {
public:
    int findLUSlength(string a, string b) {
        short str1Len = a.size(), str2Len = b.size();
        if(str1Len != str2Len) return max(str1Len, str2Len);
        else{
            if(a == b) return -1;
            else return str1Len;
        }
        return -1;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(1)

