class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0] == 1 ? 1 : 0;

        int maxLength = INT_MIN;
        int i, j;
        for(i = 0; i < n; ){
            if(nums[i] == 1){
                j = i;
                while(j < n && nums[j] == nums[i]){
                    j++;
                }
                maxLength = max(maxLength, j - i);
                i = j;
            }else{
                i++;
            }
        }
        if(maxLength == INT_MIN) return 0;
        maxLength = max(maxLength, j - i);
        return maxLength;
    }
};