class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3) return false;
        // 第一步
        int *min = new int[nums.size()];
        min[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < min[i - 1]){
                min[i] = nums[i];
            } else{
                min[i] = min[i - 1];
            }
        }
        // 第二步
        stack<int>NumStack;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(min[i] < nums[i]){
                while(!NumStack.empty() && NumStack.top() <= min[i]){ 
                    // 保证栈内元素都大于min[i]
                    NumStack.pop();
                }
                if(!NumStack.empty() && NumStack.top() < nums[i]){
                    return true;
                }
                NumStack.push(nums[i]);
            }
        }

        return false;
    }
};