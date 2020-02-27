# LeetCode-5-Longest Palindromic Substring-最长回文子串

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/1.png)

## 综述：  
\+ 方法一：  
\+ 从回文串的角度出发其其中点位置开始两边字符相等，那么对于所给的一个字符串每个字符都可以为中心点，考虑到最终最长回文串长度有奇偶数之分，则对于当前字符 s[i] 需要检查其 s[i] 是否等于 s[i -1] 和 s[i] 是否等于 s[i - 2] 两种情况。  

\+ 方法二：该方法参考题解  
\+ 使用动态规划。设置 dp(i, j) 为从 s[i] 到 s[j] 为回文（即 dp(i, j) = true），则可推出 dp(i, j) = (dp(i + 1, j - 1) && s[i] == s[j])，因为 dp(i, j) 为回文，则 dp(i + 1, j - 1) 也会回文，并 s[i] == s[j] 。通过上述可认为对于 s[i] 到 s[j] 是否为回文（true），需要判断 dp(i + 1, j - 1) && s[i] == s[j] 是否同时为 true。  
\+ 已知 dp(i, i) = true，那么对于 dp(i, i + 1) 也容易判断，因为相邻两个元素组合若为回文则该元素必须相等，所以  dp(i, i + 1) = s[i] == s[i + 1]。  
\+ 综上可使用上列方程找到最长回文子串。  
\+ 这里的二维矩阵可压缩用一维矩阵代替。  

## 改进：
\+ 使用马拉车算法


## Code-1
```
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0 || n == 1) return s;

        string result; result.push_back(s[0]);
        for(int i = 1; i < n; i++){
            int k = 2;
            while(k != 0){
                int left, right = i;
                if(k == 1 && s[i] == s[i - 1]){
                    left = i - 1;
                } else if(k == 2 && i >= 2 && s[i] == s[i - 2]){
                    left = i - 2;
                } else{
                    k--;
                    continue;
                }
                while(left >= 0 && right <= n && s[left] == s[right]){
                    left--;
                    right++;
                }
                left++;
                right--;
                if(right - left + 1 > result.size()){
                    result = string(s.begin() + left, s.begin() + right + 1);
                }
                k--;
            }
        }
        
        return result;
    }
};
```

## Code-2
```
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n == 0 || n == 1) return s;

        int maxLen = 1, start = 0, end = 0;
        vector<bool>dp(n, true);
        for(int i = n - 1; i >= 0; i--){
            for(int j = n - 1; j >= i; j--){
                if(j == i) dp[j] = true;
                else if(j == i + 1){
                    dp[j] = s[i] == s[j];
                } else{
                    dp[j] = dp[j - 1] && s[i] == s[j];
                }

                if(dp[j] && j - i + 1 > maxLen){
                    maxLen = j - i + 1;
                    start = i;
                    end = j;
                }
            }
        }

        if(maxLen == 1) return string(1, s[0]);
        else return string(s.begin() + start, s.begin() + end + 1);
    }
};
```

## 复杂度分析
方法一：  
空间复杂度O(1)  
时间复杂度O(n<sup>2</sup>)  

方法二：  
空间复杂度O(n)  
时间复杂度O(n<sup>2</sup>)  

