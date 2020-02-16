class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] < nums[n - 1]) return nums[0];
        int left = 0, right = n - 1;
        while(left < right){
            int middle = (left + right) / 2;

            if(nums[middle] <= nums[right]) right = middle;
            else left = middle;

            if(left + 1 == right) break;
        }

        return nums[right];
    }
};