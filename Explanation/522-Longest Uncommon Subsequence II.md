# LeetCode-522-Longest Uncommon Subsequence II-最长特殊序列 II

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/522.png)

## 综述：  
\+ 该题参考题解。  
\+ 对于当前字符串，判断其是否为其他字符串的子序列，如果不是则更新最大长度。  
\+ 判断字符串 str1 是否为 str2 的子序列方法：逐个遍历 str1 的字符（下标 i），然后和 str2 的字符比较（下标 j），如果相同，则 i++ 和 j++，不相同则 j++。如果 j 等于 str2 的长度，则跳出。最后判断 i 是否为 str1 的长度，如果是，则 str1 为 str2 ，如果不是，则 str1 不为 str2。  

## Code
```
class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int maxLen = -1;
        for(int i = 0; i < strs.size(); i++){
            int j = 0;
            for( ; j < strs.size(); j++){
                if(j == i) continue;
                if(isSubStr(strs[i], strs[j])){
                    break;
                }
            }
            if(j == strs.size()){
                maxLen = max(maxLen, (int)strs[i].size());
            }
        }
        return maxLen;
    }

    bool isSubStr(string str1, string str2){
        int i = 0, j = 0;
        for( ; i < str1.size() && j < str2.size(); j++){
            if(str1[i] == str2[j]){
                i++;
            }
        }
        if(i == str1.size()) return true;
        return false;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(len * n<sup>2</sup>) len 为 strs 内字符串平均长度

