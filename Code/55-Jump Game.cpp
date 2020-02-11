class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0) return false;
        if(nums.size() == 1) return true;
        
        int n = nums.size();
        for(int i = 0; i < n; ){
            if(nums[i] == 0) break;

            if(n - 1 - i <= nums[i]) return true;

            int nextPos, maxDis = -1;
            for(int j = i + 1; j <= i + nums[i]; j++){
                int curMaxDis = j + nums[j];
                if(curMaxDis > maxDis){
                    maxDis = curMaxDis;
                    nextPos = j;
                }
            }
            i = nextPos;
        }

        return false;
    }
};