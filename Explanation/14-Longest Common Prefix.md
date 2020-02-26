# LeetCode-14-Longest Common Prefix-最长公共前缀

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/14.png)

## 综述：  
\+ 同步检测。  

## Code
```
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return string();
        if(n == 1) return strs[0];

        int minLen = INT_MAX;
        for(int i = 0; i < n; i++){
            if(strs[i].size() < minLen) minLen = strs[i].size();
        }

        string result;
        for(int i = 0; i < minLen; i++){
            bool flag = true;
            for(int j = 1; j < n; j++){
                if(strs[j][i] != strs[j - 1][i]){
                    flag = false;
                    break;
                }
            }
            if(flag) result.push_back(strs[0][i]);
            else break;
        }

        return result;
    }
};
```


## 复杂度分析
空间复杂度O(n)  
时间复杂度O(n<sup>2</sup>)

