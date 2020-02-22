# LeetCode-381-Insert Delete GetRandom O(1) - Duplicates allowed-O(1) 时间插入、删除和获取随机元素 - 允许重复

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/1.png)

## 综述：  
\+ 该题参考了题解。  
\+ 本题也在[LeetCode380.常数时间插入、删除和获取随机元素](https://leetcode-cn.com/problems/insert-delete-getrandom-o1/)基础上进行改进。  
\+ 该题主要难点在于元素可以重复，那么可以使用 vector 和 multimap 存储所插入的数据。对于 multimap ，我们可以设置 <int, set<int>> ，其中 key 存储的是插入过的元素，然后 set 存储该元素在数组中出现过的位置。  
\+ 对于元素的插入，这里直接在 vector 尾部插入元素。如果该元素已在数组中，则在 multimap 中更新其位置集合（插入新的位置），如果不在，则创建位置集合并压入当前位置，然后元素和其位置集合一同插入 multimap 中。  
\+ 对于随机获取，则先计算位置：pos = rand() % nums.size()，然后直接使用将 pos 作为下标获取元素。  
\+ 这里删除基本方法和“LeetCode380.常数时间插入、删除和获取随机元素”一致，同样在数组中将最后一个元素替换到要删除的位置，那么可通过 multimap 的 find 函数找到元素，取其位置集合的第一个数值为要删除的位置，然后将该数值从位置集合中删除，然后检测位置集合是否为空，若空，则将该元素从 multimap 中删除。然后在 multimap 中找到数组中最后一个元素，在找到的情况下，将其位置集合中的数值为数组最后一个下标的元素删除，然后插入一开始数组中要删除的位置。然后将数组中最后一个元素和要删除位置的元素交换，最后将数组的最后一个元素删除。

## Code
```
class RandomizedCollection {
private:
    vector<int>nums;
    multimap<int, set<int>>numsMap;
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        auto iter = numsMap.find(val);
        if(iter == numsMap.end()){
            set<int>posSet; 
            posSet.insert(nums.size() - 1);
            numsMap.insert({val, posSet});
            return true;
        } else { 
            (iter->second).insert(nums.size() - 1);
            return false;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto iter = numsMap.find(val);
        if(iter != numsMap.end()){
            int deletePos = *((iter->second).begin());

            (iter->second).erase((iter->second).begin());
            if((iter->second).size() == 0) numsMap.erase(iter);

            auto iter2 = numsMap.find(nums[nums.size() - 1]);
            if(iter2 != numsMap.end()){
                // iter2->second is posSet
                auto iter3 = (iter2->second).find(nums.size() - 1); 
                (iter2->second).erase(iter3);
                (iter2->second).insert(deletePos);
            }

            nums[deletePos] = nums[nums.size() - 1];
            nums.erase(nums.end() - 1);
            
            return true;
        }
        return false;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int pos = rand() % nums.size();
        return nums[pos];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
```


## 复杂度分析

