// 方法一
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), minNum = nums[n - 1], count = 1;
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < minNum){
                minNum = nums[i];
                count++;
                if(count == 3) return nums[i];
            }
        }
        return nums[n - 1];
    }
};

/*
// 方法二
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size(), max1 = nums[0];
        long max2, max3;
        max2 = max3 = LONG_MIN;
        for(int i = 0; i < n; i++){
            if(nums[i] == max1 || nums[i] == max2 || nums[i] == max3) continue;
            if(nums[i] > max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            } else if(nums[i] > max2){
                max3 = max2;
                max2 = nums[i];
            } else if(nums[i] > max3){
                max3 = nums[i];
            }
        }
        if(max3 == LONG_MIN) return max1;
        return (int)max3;
    }
};
*/