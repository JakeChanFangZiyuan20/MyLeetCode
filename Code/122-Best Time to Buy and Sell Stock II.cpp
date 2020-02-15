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