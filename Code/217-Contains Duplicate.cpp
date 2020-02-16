class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return false;

        sort(nums.begin(), nums.end());

        bool result = false;
        int n = nums. size();
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1]){
                result = true;
                break;
            }
        }

        return result;
    }
};