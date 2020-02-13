# LeetCode-78-Subsets-子集

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/78.png)

## 综述：  
\+ 该题可用回溯法，则可以通过画图来模拟。  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/78-1.png)
\+ 上图已采用一定的剪枝。节点为剩余元素，连接线上的数字为从剩余元素中组成新子集的元素。那么对于图中的一个节点可以抽出节点内的每一个元素，然后形成新的节点，但这里将因为排除重复而适当剪枝，就是该节点抽出的元素必须大于其连结到其父节点的连接线上的数字。然后就是如果节点为空则直接结束本次递归调用。
\+ 对于空集可以在进行 DFS 前就加入到结果集中。


## Code
```
class Solution {
private:
    vector<int>newGroup;
    vector<vector<int>>result;
    vector<int>nums;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
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

