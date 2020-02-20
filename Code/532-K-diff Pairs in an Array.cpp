class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size(), result = 0;
        if(n == 0 || n == 1) return 0;
        if(k > 2e7) return 0;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 1; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int target = nums[i] + k;
            int left = i + 1, right = n - 1;
            while(true){
                if(nums[left] == target){
                    result++;
                    break;
                }
                if(nums[right] == target){
                    result++;
                    break;
                }
                int middle = (left + right) / 2;
                if(nums[middle] == target){
                    result++;
                    break;
                } else if(nums[middle] < target) left = middle;
                else right = middle;
                if(left + 1 == right || left == right) break;
            } 
        }

        return result;
    }
};