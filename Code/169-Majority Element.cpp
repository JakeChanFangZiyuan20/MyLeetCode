// 方法一
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>count(n, 1);
        int result = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1]){
                count[i] = count[i - 1] + 1;
                if(count[i] > n / 2){
                    result = nums[i];
                    break;
                }
            } 
        }
        return result;
    }
};

/*
// 方法二：Boyer-Moore 算法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0], count = 1, n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] == candidate) count++;
            else{
                count--;
                if(count == 0){
                    candidate = nums[i];
                    count++;
                }
            }
        }
        return candidate;
    }
};
*/