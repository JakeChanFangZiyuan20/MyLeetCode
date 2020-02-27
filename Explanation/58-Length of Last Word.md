# LeetCode-58-Length of Last Word-最后一个单词的长度

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/58.png)

## 综述：  
\+ 从后往前扫描，遇到空格跳过，遇到字字母开始计数，遇到非字符或扫描结束则返回计数

## Code
```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int strSize = s.size();
        if(strSize == 0) return strSize;

        int count = 0;
        for(int i = strSize - 1; i >= 0; i--){
            if(s[i] == ' ') continue;
            else{
                int j = i;
                for( ; j >= 0; j--){
                    if(s[j] >= 'a' && s[j] <= 'z' || s[j] >= 'A' && s[j] <= 'Z'){ 
                        count++;
                    } else{
                        return count;
                    }
                }
                if(j == -1) return count;
            }
        }

        return 0;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

