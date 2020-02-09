class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int>numsMap;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            numsMap[nums[i]] = i;
        }
        vector<int>result;
        for(int i = 0; i < n; i++){
            map<int, int>::iterator iter = numsMap.find(target - nums[i]);
            if(iter != numsMap.end() && iter->second != i){
                int a = min(i, iter->second), b = max(i, iter->second);
                result.push_back(a);
                result.push_back(b);
                break;
            }
        }
        return result;
    }
};