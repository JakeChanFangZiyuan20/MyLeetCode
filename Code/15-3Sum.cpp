class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        // 数量不足
        if(n < 3) return result;
        sort(nums.begin(), nums.end()); // 排序
        // 所有数值小于0或大于0则无解
        if(nums[0] > 0 || nums[n - 1] < 0) return result;

        for(int i = 0; i < n - 2; i++){
            if(nums[i] > 0) break; // nums[i] > 0则后面的数值也大于0
            if(i > 0 && nums[i] == nums[i - 1]) continue; // 当前数值与前一个相同
            int b = i + 1, c = n - 1; // b、c左右指针
            while(b < c){
                int curRes = nums[i] + nums[b] + nums[c];
                if(curRes == 0){
                    vector<int>cur;
                    cur.push_back(nums[i]); cur.push_back(nums[b]); cur.push_back(nums[c]);
                    result.push_back(cur); 

                    int tempb = nums[b];
                    while(b < c && nums[b] == tempb) b++; // 跳过相等
                    int tempc = nums[c];
                    while(c > b && nums[c] == tempc) c--; // 跳过相等
                }
                else if(curRes < 0){
                    int tempb = nums[b];
                    while(b < c && nums[b] == tempb) b++; // 跳过相等
                } else{
                    int tempc = nums[c];
                    while(c > b && nums[c] == tempc) c--; // 跳过相等
                }
            }
        }
        return result;
    }
};