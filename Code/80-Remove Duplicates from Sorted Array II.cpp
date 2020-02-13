class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1 || nums.size() == 2){
            return nums.size();
        }

        int n = nums.size(), result;
        for(int i = 0; i < n; ){
            if(i == n - 2){
                result = n;
                break;
            }else if(nums[i] == nums[i + 1] && nums[i + 2] == nums[i]){
                i++;
                int j;
                for(j = i + 1; j < n; j++){
                    if(nums[j] != nums[i]){
                        break;
                    }
                }
                for(j; j < n; j++){
                    if(nums[j] == nums[i] && nums[j] == nums[i - 1]){
                        continue;
                    }
                    nums[++i] = nums[j];
                }
                result = i + 1;
                break;
            }
            else{
                i++;
            }
        }
        
        return result;
    }
};