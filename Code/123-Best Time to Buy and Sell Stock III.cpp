// 代码一
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || n == 1) return 0;

        vector<int>dp1(n, 0), dp2(n, 0);
        int k = 2;
        while (k--) {
            int dpMin = prices[0];
            for (int i = 1; i < n; i++) {
                dp2[i] = max(dp2[i - 1], prices[i] - dpMin);
                dpMin = min(dpMin, prices[i] - dp1[i - 1]);
            }
            dp1 = dp2;
        }
        return dp2[n - 1];
    }
};

// 代码二
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0 || n == 1) return 0;

        int min1 = prices[0], min2 = prices[0], dp1 = 0, dp2 = 0;
        for(int i = 1; i < n; i++){
            min1 = min(min1, prices[i] - 0);
            dp1 = max(dp1, prices[i] - min1);

            min2 = min(min2, prices[i] - dp1);
            dp2 = max(dp2, prices[i] - min2);
        }
        return dp2;
    }
};

*/
