# LeetCode-380-Insert Delete GetRandom O(1)-常数时间插入、删除和获取随机元素

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/380.png)

## 综述：  
\+ 本题在写删除部分函数时参考了题解。
\+ 由于需要 O(1) 来插入和删除，那么可以使用哈希表和 vector。  
\+ 对于删除，通过 map 可以找到待删除元素下标，此时，可以将 vector 中最后一个元素复制到删除元素的位置，并在 map 中找到该元素，更新位置，然后删除 vector 的最后一个元素。对于 map，则删除需要删除的元素。参考(https://leetcode-cn.com/problems/insert-delete-getrandom-o1/solution/chang-shu-shi-jian-cha-ru-shan-chu-he-huo-qu-sui-j/)中的remove操作。

## Code
```
class RandomizedSet {
private:
    vector<int>nums;
    map<int, int>numsMap;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto iter = numsMap.find(val);
        if(iter == numsMap.end()){
            nums.push_back(val);
            numsMap[val] = nums.size() - 1;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto iter = numsMap.find(val);
        if(iter != numsMap.end()){
            int pos = iter->second;
            nums[pos] = nums[nums.size() - 1];
            nums.erase(nums.end() - 1);
            numsMap[nums[pos]] = pos;
            numsMap.erase(iter);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int pos = rand() % nums.size();
        return nums[pos];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```


## 复杂度分析

