# LeetCode-128-Longest Consecutive Sequence-最长连续序列

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/128.png)

## 综述：  
\+ 该题参考了题解。  

\+ 方法一：  
\+ 使用并查集的思想，一开始将所有的元数加入到 unordered_map 中（因为其插入、搜索的平均复杂度均为常数），即 unordered_map[nums[i]] = nums[i]，即每个元素做为一个集，在这里可设置为该集的最后一个数值。那么接下来就开始寻找每个集的 parent。对于某一个集，unordered_map[nums[i]]，就寻找是否存在 nums[i] - 1，如果存在则将 unordered_map[nums[i]] 更新为 nums[i] - 1 ，然后继续找是否存在 nums[i] - 1 - 1 ，直到不存在，则开始对下一个集寻找，即对unordered_map[nums[i + 1]] 寻找其 parent。当所有集的 parent 寻找完后，对 unordered_map 中的每个元素进行 nums[i] - unordered_map[nums[i]] ，然后取最大。  
\+ 该方法其实用时会比较长，O(n) 的时间复杂度其实只是平均，存在最差情况 O(n<sup>2</sup>)。  

\+ 方法二：该方法在方法一的基础上进行改进  
\+ 这里先用 unordered_set 来存储每一个数，那么在 unordered_set 组个遍历。假设当前是 cur ，则判断 cur - 1 是否存在，如果存在则跳过 cur ，对 unordered_set 中的下一个数进行考察，如果  cur - 1 不存在，则从 cur 开始，查找是否存在 cur + 1 ，并设置一个计数器，直到某个数 end，其中 cur 到 end 是一个连续序列，而 end + 1 并不存在，此时将计数器和最大长度比较并更新最大长度。  

## Code-1
```
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return n;

        unordered_map<int, int>group;
        for(int i = 0; i < n; i++){
            if(group.find(nums[i]) == group.end()){
                group[nums[i]] = nums[i];
            }
        }
        int maxlen = INT_MIN;
        for(auto iter = group.begin(); iter != group.end(); iter++){
            auto parent = group.find(iter->second - 1);
            while(parent != group.end()){
                iter->second = parent->first;
                parent = group.find(iter->second - 1);
            }
            maxlen = max(maxlen, iter->first - iter->second);
        }
        return maxlen + 1;
    }
};
```

## Code-2
```
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>numsSet(nums.begin(), nums.end());
        int maxLen = 0;
        for(auto num : nums){
            if(numsSet.count(num - 1)) continue;
            int cur = num, total = 1;
            while(numsSet.count(cur + 1)){
                cur++;
                total++;
            }
            maxLen = max(maxLen, total);
        }
        return maxLen;
    }
};
```

## 复杂度分析
方法一：  
空间复杂度O(n)  
时间复杂度O(n)，平均，包含最差的O(n<sup>2</sup>)  

方法二：  
空间复杂度O(n)  
时间复杂度O(n)  

