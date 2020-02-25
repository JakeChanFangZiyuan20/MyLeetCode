// 方法一
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

// 方法二
/*
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
*/