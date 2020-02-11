class Solution {
private:
    vector<int>newGroup;
    vector<vector<int>>result;
    vector<int>nums;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size() == 0) return vector<vector<int>>();

        nums = candidates;
        sort(nums.begin(), nums.end());
        if(target < nums[0]) return vector<vector<int>>();

        DFS(0, target);

        return result;
    }

    void DFS(int i, int target){
        if(target == 0){
            result.push_back(newGroup);
            return ;
        }
        for(int j = i; j < nums.size() && target - nums[j] >= 0; j++){
            if(j > i && nums[j] == nums[j - 1]) continue;
            newGroup.push_back(nums[j]);
            DFS(j + 1, target - nums[j]);
            newGroup.erase(newGroup.end() - 1);
        }
    }
};