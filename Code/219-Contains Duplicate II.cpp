class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 0) return false;

        int n = nums.size();
        map<int, int>numsMap;
        bool result = false;
        for(int i = 0; i < n; i++){
            if(numsMap.find(nums[i]) == numsMap.end()){
                numsMap[nums[i]] = i;
            } else{
                if(i - numsMap[nums[i]] <= k) return true;
                else numsMap[nums[i]] = i;
            }
        }

        return result;
    }
};