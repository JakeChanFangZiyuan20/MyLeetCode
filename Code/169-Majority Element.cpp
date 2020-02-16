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