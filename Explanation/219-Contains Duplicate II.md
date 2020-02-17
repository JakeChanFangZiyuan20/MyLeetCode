# LeetCode-219-Contains Duplicate II-存在重复元素 II

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/219.png)

## 综述：  
\+ 从左向右遍历元素，若当前元素第一次出现加入到 map（以数组元素为 key ，下标为 value ），若当前元素前面出现过则判断当前位置和前面出现过的距离（ i - numsMap[nums[i]] <= k ），若小于等于 k 则返回false，若大于，则用当前位置更新 numsMap[nums[i]]。

## Code
```
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 0) return false;

        int n = nums.size();
        map<int, int>numsMap;
        bool result = false;
        for(int i = 0; i < n; i++){
            if(numsMap.find(nums[i]) == numsMap.end()){
                numsMap[nums[i]] = i;
            } else{
                if(i - numsMap[nums[i]] <= k) return true;
                else numsMap[nums[i]] = i;
            }
        }

        return result;
    }
};
```


## 复杂度分析
空间复杂度O(n)  
时间复杂度O(n)

