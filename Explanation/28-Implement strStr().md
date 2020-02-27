# LeetCode-28-Implement strStr()-实现 strStr()

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/28.png)

## 综述：  
\+ 这里使用最容易想的方法：逐个检验。  

## 改进
\+ 使用 KMP算法

## Code
```
class Solution {
public:
    int strStr(string haystack, string needle) {
        int str1Size = haystack.size(), str2Size = needle.size();
        if(str2Size == 0) return 0;
        if(str1Size == 0) return -1;

        int result = -1;
        for(int i = 0; i < str1Size; i++){
            if(haystack[i] == needle[0]){
                int j = 0;
                for(j; j < str2Size && i + j < str1Size; j++){
                    if(needle[j] != haystack[i + j]){
                        break;
                    }
                }
                if(j == str2Size) result = i;
            }
            if(result != -1) break;
        }

        return result;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(mn)

