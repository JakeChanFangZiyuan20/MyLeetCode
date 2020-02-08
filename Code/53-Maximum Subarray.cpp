// 方法一
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int maxSum = -2147483648;
        // 构造前缀数组
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i - 1];
        }

        //
        set<int>Set;
        Set.insert(0);
        for(int i = 0; i < nums.size(); i++){
            int curMax = nums[i] - *Set.begin();
            maxSum = max(maxSum, curMax);
            Set.insert(nums[i]);
        }
        return maxSum;
    }
};

/*
//方法二
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int preSum = 0, maxSum = 0;
        preSum = maxSum = nums [0];
        for(int i = 1; i < nums.size(); i++){
            if(preSum < 0) preSum = nums[i];
            else{
                preSum += nums[i];
            }
            maxSum = max(maxSum, preSum);
        }
        return maxSum;
    }
};
*/