// 方法一
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

/*
// 方法二
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>output(n, 1);
        // 构造左乘积序列
        for(int i = 1; i < n; i++){
            output[i] = nums[i - 1] * output[i - 1];
        }

        int last = 1;
        for(int i = n - 2; i >= 0; i--){
            last *= nums[i + 1];
            output[i] *= last; 
        }
        
        return output;
    }
};
*/