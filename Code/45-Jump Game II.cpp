class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        
        int n = nums.size(), count = 0;
        for(int i = 0; i < n; ){
            count += 1;
            if(n - 1 - i <= nums[i]) return count;

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

        return count;
    }
};