// 方法一
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return n;

        unordered_map<int, int>group;
        for(int i = 0; i < n; i++){
            if(group.find(nums[i]) == group.end()){
                group[nums[i]] = nums[i];
            }
        }
        int maxlen = INT_MIN;
        for(auto iter = group.begin(); iter != group.end(); iter++){
            auto parent = group.find(iter->second - 1);
            while(parent != group.end()){
                iter->second = parent->first;
                parent = group.find(iter->second - 1);
            }
            maxlen = max(maxlen, iter->first - iter->second);
        }
        return maxlen + 1;
    }
};

/*
// 方法二
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>numsSet(nums.begin(), nums.end());
        int maxLen = 0;
        for(auto num : nums){
            if(numsSet.count(num - 1)) continue;
            int cur = num, total = 1;
            while(numsSet.count(cur + 1)){
                cur++;
                total++;
            }
            maxLen = max(maxLen, total);
        }
        return maxLen;
    }
};
*/