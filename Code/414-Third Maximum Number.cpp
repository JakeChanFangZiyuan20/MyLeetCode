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