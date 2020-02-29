# LeetCode-434-Number of Segments in a String-字符串中的单词数

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/434.png)

## 综述：  
\+ 按要求写代码。  

## Code
```
class Solution {
public:
    int countSegments(string s) {
        int len = s.size();
        int result = 0;
        for(int i = 0; i < len; i++){
            if(s[i] != ' '){
                int j = i;
                while(j < len && s[j] != ' '){
                    j++;
                }
                result++;
                i = j--;
            }
        }
        return result;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

