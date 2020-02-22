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