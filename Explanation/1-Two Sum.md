# LeetCode-1-Two Sum-两数之和

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/1.png)

## 综述：  
\+ 该题参考了题解。  
\+ 对于当前值x，其下标为i，需要找到另外一个值为y，下标为j，使得x+y=target=nums[i]+nums[j]。  
\+ 难点在于寻找值y，暴力的话最终会O(n<sup>2</sup>)。  
\+ 这里采取哈希的方法，然后第一次遍历将x做为key，i做为value放入到map中。  
\+ 进行第二次遍历时，在map中寻找是否存在key值为target-nums[i]的值，若存在，则检查其对应value，即对应下标是否和当前下标i相同，若不同则返回当前下标和找到的value所组成的小前大后数对。  

## Code
```
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
```


## 复杂度分析
空间复杂度O(n)  
时间复杂度O(n)

