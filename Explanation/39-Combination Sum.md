# LeetCode-39-Combination Sum-组合总和

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/39.png)

## 综述：  
\+ 该题参考了题解。  
\+ 本题使用回溯算法，对于回溯算法，可画出图。下面借用LeetCode题解区一位解答者的话：  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/39-1.png)
\+ 过程：在进行递归求解前可先将数组排序。然后让target减去数组中的数，分别获取减去后的数，然后在剩余的数继续逐个减去。下图为解释：  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/39-2.png)
\+ 在上图中，根节点为target，连接线上的数为所给数组的中的数，也是需要减去的数，减去后分别获得一个数，成为新的target，明显此处可用递归。  
\+ 通过观察，递归返回条件是减去后为0，即对于一个新的递归，若target值为0，即可将此一路上减去的值形成一个新答案。  
\+ 通过观察，也可发现若减去后小于0，则应该停止操作。  
\+ 对于重复数组，通过观察，发现在一个一个数减去的过程中，若当下减去的数比之前减去的数小，容易出现重复，那么可以在获得一个新的taget值时并减去数时，从上一次减的地方开始逐个减即可避免，从图上来说就是让连接边上的数从上到小一路下来为增大。  


## Code
```
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
```


## 复杂度分析


