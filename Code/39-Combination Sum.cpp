class Solution {
private:
    vector<vector<int>>result;
    vector<int>nums;
    vector<int>newGroup;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0) return vector<vector<int>>();

        sort(candidates.begin(), candidates.end()); // 使数组有序
        if(candidates[0] > target) return vector<vector<int>>();

        nums = candidates;
        DFS(0, target);
        
        return result;
    }

    void DFS(int i, int target){
        if(target == 0){
            result.push_back(newGroup);
            return ;
        }
        for(int j = i; j < nums.size() && target - nums[j] >= 0; j++){
            newGroup.push_back(nums[j]);
            DFS(j, target - nums[j]);
            newGroup.erase(newGroup.end() - 1);
        }
    }
};