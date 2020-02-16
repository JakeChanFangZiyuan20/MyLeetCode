class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1){
            if(nums[0] == s) return 1;
            else return 0;
        }

        if(s <= nums[0]) return 1;

        int n = nums.size();
        for(int i = 1; i < n; i++){
            nums[i] += nums[i - 1];
        }

        if(nums[n - 1] < s) return 0;

        int result = INT_MAX;
        for(int i = n - 1; i >= 0; i--){
            if(nums[i] == s){
                result = min(result, i + 1);
                break;
            }
            if(nums[i] < s){
                break;
            }
            vector<int>::iterator iter = upper_bound(nums.begin(), nums.end(), nums[i] - s);
            if(iter != nums.end()){
                result = min(result, i - (int)(iter - nums.begin()) + 1);
            }
        }

        return result;
    }
};