// 方法一
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 排序时间复杂度O(nlogn)
        int n = nums.size(), result;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1]){
                result = nums[i];
                break;
            }
        }
        return result;
    }
};

/*
// 方法二
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, n = nums.size();
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                fast = 0;
                while(slow != fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                break;
            }
        }
        return slow;
    }
};
*/