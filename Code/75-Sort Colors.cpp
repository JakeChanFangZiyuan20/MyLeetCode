class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() == 0) return ;

        int n = nums.size(), left = 0, right = n - 1;
        for(int i = 0; i <= right; ){
            if(nums[i] == 1){
                i++;
                continue;
            }
            if(nums[i] == 0){
                swap(nums[i], nums[left++]);
                i++;
                continue;
            }
            if(nums[i] == 2){
                swap(nums[i], nums[right--]);
            }
        }
    }
};