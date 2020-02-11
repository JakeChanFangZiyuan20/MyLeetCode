class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0) return 0;

        int n = nums.size(), left = 0, right = n - 1;
        if(target < nums[0]) return 0;
        if(target > nums[n - 1]) return n;

        int pos;
        while(left <= right){
            if(nums[left] == target) return left;
            if(nums[right] == target) return right;

            int middle = (left + right) / 2;
            if(nums[middle] == target) return middle;

            if(nums[middle] < target) left = middle;
            else right = middle;
            
            if(left + 1 == right) break;
        }
        pos = left + 1;

        return pos;
    }
};