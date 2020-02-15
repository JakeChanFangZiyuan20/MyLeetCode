class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        int n = nums.size(), maxResult = nums[0], curMax = nums[0], curMin = nums[0];
        for(int i = 1; i < n; i++){
            int tempMax = max(nums[i], max(curMax * nums[i], curMin * nums[i]));
            int tempMin = min(nums[i], min(curMax * nums[i], curMin * nums[i]));
            curMax = tempMax; curMin = tempMin;
            maxResult = max(maxResult, curMax);
        }

        return maxResult;
    }
};