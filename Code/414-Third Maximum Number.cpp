// 方法一
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), minNum = nums[n - 1], count = 1;
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < minNum){
                minNum = nums[i];
                count++;
                if(count == 3) return nums[i];
            }
        }
        return nums[n - 1];
    }
};

/*
// 方法二
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>numsSet;
        int n = nums.size(), maxNum = nums[0];
        numsSet.insert(nums[0]);
        for(int i = 1; i < n; i++){
            numsSet.insert(nums[i]);
            if(nums[i] > maxNum) maxNum = nums[i];
        }
        int result;
        if(numsSet.size() < 3) result = maxNum;
        else{
            int count = 0;
            for(auto iter = numsSet.begin(); iter != numsSet.end(); iter++){
                count += 1;
                if(count == numsSet.size() - 2){
                    result = *iter;
                    break;
                }
            }
        }
        return result;
    }
};
*/

/*
// 方法三
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size(), maxNum = nums[0];
        set<int>numsSet; numsSet.insert(nums[0]);

        for (int i = 1; i < n; i++) {
            if (nums[i] > maxNum) maxNum = nums[i];

            if (numsSet.find(nums[i]) == numsSet.end()) {
                if (numsSet.size() < 3) {
                    numsSet.insert(nums[i]);
                }
                else if (nums[i] > * numsSet.begin()) {
                    numsSet.erase(numsSet.begin());
                    numsSet.insert(nums[i]);
                }
            }
        }

        int result;
        if (numsSet.size() < 3) result = maxNum;
        else result = *numsSet.begin();
        return result;
    }
};
*/