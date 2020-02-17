class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), last = 1;
        vector<int>output(n, 0);

        int zero_pos = -1, zero_count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                if(zero_pos == -1) zero_pos = i;
                zero_count++;
                if(zero_count >= 2){
                    return output;
                }
            }
        }
        if(zero_pos != -1){
            for(int i = 0; i < n; i++){
                if(i == zero_pos) continue;
                last *= nums[i];
            }
            output[zero_pos] = last;
            return output;
        }

        for(int i = 0; i < n; i++){
            if(i == 0){
                for(int j = 1; j < n; j++){
                    last *= nums[j];
                }
                output[i] = last;
            } else{
                last = output[i] = last / nums[i] * nums[i - 1];
            }
        }
        return output;
    }
};