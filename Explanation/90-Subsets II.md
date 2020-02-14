# LeetCode-90-Subsets II-子集 II

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/90.png)

## 综述：  
\+ 本题和[LeetCode78.子集](https://leetcode-cn.com/problems/subsets/)基本一样，只需在抽出元素时保证重复元素只抽一次就行，即在排序的情况下，当前数值不等于前一个数值。  

## Code
```
class Solution {
private:
    vector<int>newGroup;
    vector<vector<int>>result;
    vector<int>nums;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if(nums.size() == 0) return vector<vector<int>>();

        sort(nums.begin(), nums.end());

        this->nums = nums;
        result.push_back(vector<int>());
        DFS();

        return result;
    }

    void DFS(){
        if(nums.size() == 0) return ;
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1])continue;
            if(newGroup.size() && nums[i] < *(newGroup.end() - 1)) continue;
            newGroup.push_back(nums[i]);
            result.push_back(newGroup);
            int cur = nums[i];
            nums.erase(nums.begin() + i);
            DFS();
            nums.insert(nums.begin() + i, cur);
            newGroup.erase(newGroup.end() - 1);
        }
    }
};
```


## 复杂度分析

