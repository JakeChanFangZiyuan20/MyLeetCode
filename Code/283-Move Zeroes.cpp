class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 0) return ;
        if(nums.size() == 1) return ;

        int n = nums.size();
        for(int i = 0, j = i + 1; j < n; i++, j++){
            if(nums[i] != 0) continue;
            else{
                for(j; j < n; j++){
                    if(nums[j] != 0){
                        swap(nums[i], nums[j]);
                        break;
                    }
                }
            }
        }
    }
};