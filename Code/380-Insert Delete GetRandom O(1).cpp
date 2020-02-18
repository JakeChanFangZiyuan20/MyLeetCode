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