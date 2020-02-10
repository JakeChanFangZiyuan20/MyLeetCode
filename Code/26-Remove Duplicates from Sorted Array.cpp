// 第一版
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();

        for(vector<int>::iterator iter = nums.begin(); iter != nums.end() - 1; ){
            if(*iter == *(iter + 1)) {
                nums.erase(iter);
            } else{
                iter++;
            }
        }

        return nums.size();
    }
};

/*
// 第二版
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();

        for(vector<int>::iterator iter1 = nums.begin(); iter1 != nums.end() - 1; ){
            if(*(iter1 + 1) == *iter1){
                vector<int>::iterator iter2 = iter1 + 1;
                while(iter2 != nums.end() && *iter2 == *iter1) iter2++;
                iter1 = nums.erase(iter1 + 1, iter2);
                if(iter1 == nums.end()) return nums.size();
            } else{
                iter1++;
            }
        }

        return nums.size();
    }
};
*/

/*
// 第三版
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();

        int i = 0, n = nums.size();
        for(int j = 1; j < n; j++){
            if(nums[j] != nums[i]){
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};
*/
