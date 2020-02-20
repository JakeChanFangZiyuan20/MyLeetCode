class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return vector<int>();
        vector<int>result;
        for(int i = 0; i < n; i++){
            if(nums[abs(nums[i]) - 1] < 0){
                result.push_back(abs(nums[i]));
                continue;
            }
            nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        return result;
    }
};