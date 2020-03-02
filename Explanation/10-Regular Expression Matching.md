# LeetCode-10-Regular Expression Matching-正则表达式匹配

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/10.png)

## 综述：  
\+ 该题参考了题解。  
\+ 该题时用动态规划，主要难点在于 “ * ”，因为它可以使得其前一个字符匹配 0 或多次。  
\+ 这里使用 dp[i][j] 表示 p 中前 j 个字符是否匹配 s 中前 i 个字符，考虑到 s 和 p 可能为空，则可建立行数为 s.size() + 1 和 列数为 p.size() + 1 的二维数组。  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/10-1.png)  
\+ 通过遍历二维表进行填值。  
\+ 当 'a' <= p[j] && p[j] <= 'z' || p[j] == '.' 时，比较 p[j - 1] == s[i - 1] || p[j - 1] == '.' ，判断是否两个字符匹配，若匹配则 dp[i][j] = dp[i - 1][j - 1] 。因为当前 s[i] 和 p[j] 匹配后，dp[i][j] 的值取决于 p 中前 j - 1 个字符是否匹配 s 中前 i - 1 个字符。  
\+ 当 p[j - 1] == '*' 时，需要分情况讨论：  
\+ &emsp; 当 p[j - 1] == s[i] :  
\+ &emsp; 匹配 0 个，dp[i][j] = dp[i][j - 2] ；  
\+ &emsp; 匹配 1 个，dp[i][j] = dp[i][j - 1] ；  
\+ &emsp; 匹配多个，dp[i][j] = dp[i - 1][j] ；  
\+ &emsp; 以上三者为“或”的关系。  
\+ &emsp; 当 p[j - 1] != s[i] :  
\+ &emsp; dp[i][j] = dp[i][j - 2] ；  
  
\+ 对于二维数，需要初始化操作，对于第一列，空 p 只能和空 s 进行匹配，则第一列只有第一个元素是 true。  
\+ 对于第一行，此时 s 为空串，如果 'a' <= p[j] && p[j] <= 'z' || p[j] == '.' ，则元素为 false，如果 p[j] == '*' ，则 dp[0][j] = dp[0][j - 2]。  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/10-2.png)  


## Code
```
class Solution {
public:
    bool isMatch(string s, string p) {
        int strLen = s.size(), pLen = p.size();
        vector<vector<bool>>dp(strLen + 1, vector<bool>(pLen + 1, false));

        // init
        dp[0][0] = true;
        for(int j = 1; j <= pLen; j++){ // 1st row
            if(p[j - 1] == '*'){
                dp[0][j] = dp[0][j - 2];
            }
        }

        // start
        for(int i = 1; i <= strLen; i++){
            for(int j = 1; j <= pLen; j++){
                if(p[j - 1] == '*'){
                    if(s[i - 1] == p[j - 2] || p[j - 2] == '.'){
                        dp[i][j] = dp[i][j - 1] || dp[i][j-2] || dp[i - 1][j];
                    } else{
                        dp[i][j] = dp[i][j - 2];
                    }
                } else{
                    if(p[j - 1] == s[i - 1] || p[j - 1] == '.'){
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }

        return dp[strLen][pLen];
    }
};
```


## 复杂度分析
空间复杂度O(mn)  
时间复杂度O(n<sup>2</sup>)

