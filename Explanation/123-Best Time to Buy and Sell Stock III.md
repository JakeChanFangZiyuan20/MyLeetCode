# LeetCode-123-Best Time to Buy and Sell Stock III-买卖股票的最佳时机 III

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/123.png)

## 综述：  
\+ 该题参考了题解。  
\+ 一开始想到的是在一个趋势向上的区间找到一个数，然后会有 n 区间 n 个数，然后取最大的两个，但对于 [6,1,3,2,4,7] 这样的样例会只计算出 6 ， 即只取了 1 和 7，但实际上取 1 和 3，然后 2 和 7 ，这样会计算出 7，比 6 要大，那么就是说上述方法是不正确的。  
\+ 参考题解中的动态规划方法，思考当前 i ，dp[i] 为前 i 天的最大利润，是否存在 dp[i] 和 dp[i - 1] 的关系，即是否存在 dp[i] 和 dp[i - 1] 的状态方程。考虑到这里是最多只能两次交易，涉及的条件可以看出只使用 dp[i] 和 dp[i - 1] 是不足够的。  
\+ 所以我们假设 dp[i][k] 为前 i 天的最大利润，其中 i 表示前 i 天，k 表示前 i 天最多交易次数，那么对于第 i 天就会有交易或者不交易两种情况。  
\+ 若第 i 天不交易，则 dp[i][k] = dp[i - 1][k]，即第 i 天的最大利润是其前一天的最大利润。  
\+ 若第 i 天交易，为了获取最大利润，在第 i 天卖出股票，因为卖出之前一定需要有买入，所以可以是在第 0 到 i - 1 天买入，又因为在第 i 天交易，所以在这次交易之前还有 k - 1 次交易，则有：  
\+ &emsp;&emsp; p[i] - p[0] ，在第 0 天买入；  
\+ &emsp;&emsp; p[i] - p[1] + dp[0][k - 1] ，在第 1 天买入，需要加上第 0 天的前一天的最大利润；  
\+ &emsp;&emsp; p[i] - p[2] + dp[1][k - 1] ，在第 2 天买入，需要加上第 1 天的前一天的最大利润；  
\+ &emsp;&emsp;&emsp;&emsp; ···  
\+ &emsp;&emsp; p[i] - p[j] + dp[j - 1][k - 1] ，在第 j 天买入，需要加上第 j - 1 天的前一天的最大利润；  
\+ 综上，dp[i][k] = max(dp[i - 1][k], p[i] - p[0], p[i] - p[1] + dp[0][k - 1], ···, p[i] - p[j] + dp[j - 1][k - 1])，其中 j 为 1 到 i - 1。  
  
\+ 初始上看，我们可以建立一个二维数组，初始化时第一行和第一列为 0，然后按每一列进行填空，然后在找到最大值即可。  
\+ 但使用二维数组会重复计算很多次，并且通过计算后，二维数组中某些列完全可以覆盖，所以我们选择使用一维数组代替二维数组。  
\+ （这部操作结合代码）对于 dp[i][k]，需要计算多个值中的最大值，但通过对 p[i] - p[j] + dp[j - 1][k - 1] 的观察，我们可以发现在 j 为 1 到 i - 1 时，只需要找 p[j] - dp[j - 1][k - 1] 的最小值 dpMin，则可以使 p[i] - p[j] + dp[j - 1][k - 1] 最大。那么可以先将最小值设置为 p[0]，然后再从 i = 1 开始更新，更新完后比较当前 dpMin 和 prices[i] - dp[i - 1][k - 1] 大小然后更新 dpMin。  
\+ 最后的结果将会是 dp[n - 1][2]，n 为总天数。  
  
\+ 上面使用了按列来计算的方法，代码对应 Code-1，但换个角度，也可以按行填，那么只需设置 min1, min2, dp1, dp2 ，其中 dp1 和 dp2 对应当前 i 的最多一次交易和最多两次交易的值，min1 和 min2 为 两列的 p[j] - dp[j - 1][k - 1] 的最小值 dpMin，那么结合 Code-2，即可看做是  Code-1 的按行填充，并且最后结果直接返回 dp2 即可。  

## Code-1
```
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
```

## Code-2
```
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
```

## 复杂度分析
代码一：  
空间复杂度O(n)  
时间复杂度O(n)  

代码二：  
空间复杂度O(1)  
时间复杂度O(n)  
