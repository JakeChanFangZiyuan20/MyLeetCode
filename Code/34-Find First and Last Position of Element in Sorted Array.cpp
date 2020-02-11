class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return vector<int>(2, -1);
        if(nums.size() == 1){
            if(nums[0] == target) return vector<int>(2, 0);
            else return vector<int>(2, -1);
        }
        
        vector<int>res(2, -1);
        int n = nums.size(), left = 0, right = n - 1;
        if(target > nums[n - 1] || target < nums[0]) return res;

        // 找左边界
        while(left < right){
            int middle = (left + right) / 2;
            if(nums[middle] < target) left = middle;
            else right = middle;
            if(left + 1 == right) break;
        }
        if(nums[left] == target) res[0] = left;
        else if(nums[right] == target) res[0] = right;
        else return res;

        // 找右边界
        left = res[0]; right = n -1;
        while(left < right){
            int middle = (left + right) / 2;
            if(nums[middle] <= target) left = middle;
            else right = middle;
            if(left + 1 == right) break;
        }
        if(nums[right] == target) res[1] = right;
        else if(nums[left] == target) res[1] = left;
        else return res;

        return res;
    }
};