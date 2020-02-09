class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0;
        int n = nums.size();
        if(n < 3) return res;

        sort(nums.begin(), nums.end());

        res = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < n - 2; i++){
            int l = i + 1, r = n - 1;
            while(l < r){
                int cur = nums[i] + nums[l] + nums[r];
                if(cur == target) return target;
                
                //比较距离
                if(abs(res - target) > abs(cur - target)){
                    res = cur;
                }
                if(cur < target){
                    int templ = nums[l];
                    while(l < r && nums[l] == templ) l++;
                } else{
                    int tempr = nums[r];
                    while(r > l && nums[r] == tempr) r--;
                }
            }
        }
        return res;
    }
};