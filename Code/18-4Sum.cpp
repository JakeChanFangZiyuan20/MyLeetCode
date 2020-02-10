// 原版本
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        int n = nums.size();
        if(n < 4) return res;

        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 3; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j = i + 1; j < n - 2; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = n - 1;
                while(left < right){
                    int curSum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(curSum == target){
                        vector<int> curRes;
                        curRes.push_back(nums[i]);
                        curRes.push_back(nums[j]);
                        curRes.push_back(nums[left]);
                        curRes.push_back(nums[right]);
                        res.push_back(curRes);

                        int templeft = nums[left];
                        while(left < right && nums[left] == templeft) left++;
                        int tempright = nums[right];
                        while(right > left && nums[right] == tempright) right--;
                    } else if(curSum < target){
                        int templeft = nums[left];
                        while(left < right && nums[left] == templeft) left++;
                    } else{
                        int tempright = nums[right];
                        while(right > left && nums[right] == tempright) right--;
                    }
                }
            }
        }

        return res;
    }
};

/*
// 改进版
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        int n = nums.size();
        if(n < 4) return res;

        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 3; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int min = nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
            if(min > target) break;

            int max = nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3];
            if(max < target) continue;

            for(int j = i + 1; j < n - 2; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;

                int min2 = nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
                if(min2 > target) continue;

                int max2 = nums[i] + nums[j] + nums[n - 1] + nums[n - 2];
                if(max2 < target) continue;

                int left = j + 1, right = n - 1;
                while(left < right){
                    int curSum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(curSum == target){
                        vector<int> curRes;
                        curRes.push_back(nums[i]);
                        curRes.push_back(nums[j]);
                        curRes.push_back(nums[left]);
                        curRes.push_back(nums[right]);
                        res.push_back(curRes);

                        int templeft = nums[left];
                        while(left < right && nums[left] == templeft) left++;
                        int tempright = nums[right];
                        while(right > left && nums[right] == tempright) right--;
                        
                    } else if(curSum < target){
                        int templeft = nums[left];
                        while(left < right && nums[left] == templeft) left++;
                    } else{
                        int tempright = nums[right];
                        while(right > left && nums[right] == tempright) right--;
                    }
                }
            }
        }

        return res;
    }
};
*/