class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return false;
        bool result = false;
        for(int i = 0; i < n; i++){
            int slow = i, fast = i;
            bool reverse = false, loopOfOne = false;
            do{
                int lastSlow = slow;

                if(abs(nums[slow]) % n != 0){
                    int nextSlow = slow + nums[slow];
                    if(0 <= nextSlow && nextSlow <= n - 1) slow = nextSlow;
                    else if(nextSlow < 0) slow = n - abs(nextSlow) % n;
                    else slow = abs(nextSlow) % n;
                }

                if(nums[lastSlow] > 0 && nums[slow] <0 || 
                        nums[lastSlow] < 0 && nums[slow] > 0){
                    reverse = true;
                    break;
                }
                
                int lastFast;
                for(int k = 1; k <= 2; k++){
                    lastFast = fast;

                    if(abs(nums[fast]) % n != 0){
                        int nextFast = fast + nums[fast];
                        if(0 <= nextFast && nextFast <= n - 1) fast = nextFast;
                        else if(nextFast < 0) fast = n - abs(nextFast) % n;
                        else fast = abs(nextFast) % n;
                    }

                    if(nums[lastFast] > 0 && nums[fast] <0 || 
                            nums[lastFast] < 0 && nums[fast] > 0){
                        reverse = true;
                        break;
                    }
                }
                if(reverse) break;

                if(lastFast == fast){
                    loopOfOne = true;
                    break;
                }
                
            }while(slow != fast);

            if(reverse || loopOfOne) continue;

            result = true;
            break;
        }
        return result;
    }
};