class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 1;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0 &&nums[i] != i + 1 && nums[i] <= n 
                    && nums[nums[i] - 1] != nums[i]){
                swap(nums[nums[i] - 1], nums[i]);
                i--;
            }
        } 
        int result = n + 1;
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1) {
                result = i + 1;
                break;
            }
        }
        return result;
    }
};