class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        if(nums.size() == 1) {
            if(nums[0] == target) return true;
            else return false;
        }

        int n = nums.size();

        // 先寻找旋转点
        bool hasRotatePoint = false;
        int left = 0, right = n - 1;
        while(left < right){
            if(nums[left] == target) return true;
            if(nums[right] == target) return true;

            int middle = (left + right) / 2;
            if(nums[middle] == target) return true;

            if(nums[middle] == nums[left]){
                left++;
                continue;
            }

            if(nums[middle] <= nums[right]) right = middle;
            else left = middle;
            if(left + 1 == right) break;
        }
        //cout << left << ',' << right;

        // 查找target值
        if(nums[left] <= nums[right]){ // 数组旋转后仍有序
            int a = 0, b = n - 1;
            while(a < b){
                if(nums[a] == target) return true;
                if(nums[b] == target) return true;

                int middle = (a + b) /2;
                if(nums[middle] == target) return true;

                if(nums[middle] < target) a = middle;
                if(nums[middle] > target) b = middle;
                if(a + 1 == b) break;
            }
        } else{
            int a, b;
            if(nums[0] <= target && target <= nums[left]){
                a = 0;
                b = left;
            } else if(nums[right] <= target && target <= nums[n - 1]){
                a = right;
                b = n - 1;
            } else{
                return false;
            }
            while(a < b){
                if(nums[a] == target) return true;
                if(nums[b] == target) return true;

                int middle = (a + b) /2;
                if(nums[middle] == target) return true;

                if(nums[middle] < target) a = middle;
                if(nums[middle] > target) b = middle;
                if(a + 1 == b) break;
            }
        }

        return false;
    }
};