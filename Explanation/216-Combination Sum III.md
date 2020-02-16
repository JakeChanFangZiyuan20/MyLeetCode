# LeetCode-216-Combination Sum III-组合总和 III

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/216.png)

## 综述：  
\+ 这里采用回溯算法，n 减去 1 到 9，然后形成一个新 n，进入递归。  
\+ 递归结束条件是：新组合元素个数大于k；在新 n 为 0 时（一个组合形成），新组合元素个数为 k，则加入到结果中，小于则递归结束。  
\+ 剪枝：减去的数必须小于等于已有组合中的最后一个数。  

## Code
```
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
```


## 复杂度分析

