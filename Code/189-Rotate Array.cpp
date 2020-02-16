class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 0 || nums.size() == 1 || k == 0) return ;

        int n = nums.size(), count = k % n;
        for(int i = 1; i <= count; i++){
            nums.insert(nums.begin(), *(nums.end() - 1));
            nums.erase(nums.end() - 1);
        }
    }
};