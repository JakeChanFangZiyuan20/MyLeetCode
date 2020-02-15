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