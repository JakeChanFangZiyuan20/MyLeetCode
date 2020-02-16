class Solution {
private:
    int k;
    vector<vector<int>>result;
    vector<int>newGroup;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        this->k = k;

        DFS(n);

        return result;
    }

    void DFS(int target){
        if(newGroup.size() > k) return ;
        if(target == 0){
            if(newGroup.size() == k){
                result.push_back(newGroup);
            }
            return ;
        }
        for(int i = 1; i <= 9; i++){
            if(newGroup.size() > 0 && i <= *(newGroup.end() - 1)) continue;
            newGroup.push_back(i);
            DFS(target - i);
            newGroup.erase(newGroup.end() - 1);
        }
    }
};