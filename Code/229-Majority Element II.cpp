// 方法一
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 0) return vector<int>();
        if(nums.size() == 1) return nums;
        if(nums.size() == 2){
            if(nums[0] != nums[1]) return nums;
            else{
                return vector<int>(1, nums[0]);
            }
        }

        sort(nums.begin(), nums.end());

        vector<int>result;
        int n = nums.size(), limit = n / 3;
        for(int i = 0; i < n; ){
            int count = 1, j = i + 1;
            for(j; j < n; j++){
                if(nums[j] == nums[i]){
                    count++;
                    if(count > limit){
                        result.push_back(nums[i]);
                        break;
                    } 
                } else{
                    break;
                }
            }
            while(j < n && nums[j] == nums[i]){
                j++;
            }
            i = j;
        }

        return result;
    }
};

/*
// 方法二：基于Boyer-Moore算法
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() == 0) return nums;

        vector<int>result;
        int n = nums.size();
        int candidate1 = nums[0], candidate2 = nums[0], count1 = 0, count2 = 0;
        
        // Step 1: find 2 candidates
        for(int i = 0; i < n; i++){
            if(nums[i] == candidate1){
                count1++;
            } else if(nums[i] == candidate2){
                count2++;
            } else if(count1 == 0){
                candidate1 = nums[i];
                count1 = 1;
            } else if(count2 == 0){
                candidate2 = nums[i];
                count2 = 1;
            } else{
                count1--;
                count2--;
            }
        }

        // check whether these 2 candidates satisfy
        count1 = count2 = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == candidate1) count1++;
            else if(nums[i] == candidate2) count2++;
        }
        if(count1 > n / 3) result.push_back(candidate1);
        if(count2 > n / 3) result.push_back(candidate2);

        return result;
    }
};
*/