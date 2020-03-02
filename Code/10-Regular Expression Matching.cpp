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