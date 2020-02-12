class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0) return vector<int>();

        if(digits[0] == 0) return vector<int>(1, 1);
        
        int flag = 0, n = digits.size();
        int curSum = digits[n - 1] + 1 + flag;
        digits[n - 1] = curSum % 10;
        flag = curSum / 10;
        for(int i = n - 2; i >= 0; i--){
            if(flag == 0) break;
            curSum = digits[i] + flag;
            digits[i] = curSum % 10;
            flag = curSum / 10;
        }
        if(flag){
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};