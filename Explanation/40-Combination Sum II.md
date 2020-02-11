# LeetCode-40-Combination Sum II-组合总和 II

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/40.png)

## 综述：  
\+ 该题解法同[LeetCode40.组合总和 II](https://leetcode-cn.com/problems/combination-sum-ii/)基本相同，解法可见[Combination Sum II](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/Explanation/40-Combination%20Sum%20II.md)。  
\+ 不同的地方在于要调过重复的地方来避免出现重复解，以及每个数只能用一次（在递归函数中，从上一次减的地方的下一个开始减）。

## Code
```
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
```


## 复杂度分析
