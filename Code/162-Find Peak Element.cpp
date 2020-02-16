class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), left = 0, right = n - 1;
        if(n == 1) return 0;
        if(n == 2) return nums[0] > nums[1] ? 0 : 1;
        while(left < right){
            int middle = (left + right) / 2;

            if(nums[middle] < nums[middle + 1]) left = middle;
            else if(nums[middle] > nums[middle - 1]){
                return middle;
            } else{
                right = middle;
            }

            if(left + 1 == right){
                if(left == 0) return left;
                if(right == n - 1) return n - 1;
            }
        }

        return left;
    }
};