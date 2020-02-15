# LeetCode-121-Best Time to Buy and Sell Stock-买卖股票的最佳时机

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/121.png)

## 综述：  
\+ 该题一开始想到的是找到最小值，然后在最小值后面找到最大值，然后相减获得最大利润，提交后发现解答错误，说明本人不适合炒股。  
\+ 正确做法是：从后向前遍历，并设置最大值 max，每遍历一个数值，比较其与 max 的大小，若大于则更新 max，并将该数值归 0，若小于则相减并将相减值赋值到当前数值。从后往前遍历完成后，找到最大值返回。  

## Code
```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1) return 0;

        int n = prices.size(), max = prices[n - 1];
        prices[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--){
            if(prices[i] == max){
                prices[i] = 0;
            } else if(prices[i] > max){
                max = prices[i];
                prices[i] = 0;
            } else{
                prices[i] = max - prices[i];
            }
        }

        int result = prices[0];
        for(int i = 1; i < n; i++){
            if(prices[i] > result) result = prices[i];
        }

        return result;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

