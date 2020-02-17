class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int  n = nums.size(), result;
        if(nums[n - 1] == n - 1) return n;
        for(int i = 0; i < n; i++){
            if(nums[i] != i){
                result = i;
                break;
            }
        }
        return result;
    }
};

/*
// 方法二：
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i = 1; i <= n; i++){
            sum += i;
            sum -= nums[i - 1];
        }
        return sum;
    }
};
*/

/*
// 方法三：
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), XOR = n;
        for(int i = 0; i < n; i++){
            XOR ^= i;
        }
        for(int i = 0; i < n; i++){
            XOR ^= nums[i];
        }
        return XOR;
    }
};
*/