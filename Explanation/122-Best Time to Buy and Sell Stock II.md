# LeetCode-122-Best Time to Buy and Sell Stock II-买卖股票的最佳时机 II

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/122.png)

## 综述：  
\+ 这里使用贪心算法。  
\+ 从左到右遍历每一个数字，每当到 i，则开始从其后一个元素开始继续沿着价格上涨的趋势遍历，当价格下降立刻停止。设当前 i，往后遍历到 j，存在 prices[j] < prices[j - 1]，则此时满足从 i 到 j - 1 价格一直有保持不变或上升的趋势，然后获得利润 prices[j - 1] - prices[i]，然后更新 i 的位置，即 i = j。

## Code
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       if(prices.size() == 0) return 0;

        int n = prices.size(), result = 0;
        for(int i = 0; i < n; ){
            int j = i + 1;
            for(j ; j < n; j++){
                if(prices[j] < prices[j - 1]){
                    break;
                }
            }
            if(i + 1 != j){
                result += (prices[j - 1] - prices[i]);
            }
            i = j;
        }

       return result; 
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

