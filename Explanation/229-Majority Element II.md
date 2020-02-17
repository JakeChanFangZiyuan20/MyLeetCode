# LeetCode-229-Majority Element II-求众数 II

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/229.png)

## 综述：  
\+ 方法一：  
\+ 先对数组排序，然后从左到右遍历数组数元素出现个数，符合要求则提取。  

\+ 方法二：基于Boyer-Moore算法  
\+ 基于[LeetCode169.多数元素](https://leetcode-cn.com/problems/majority-element/)中使用Boyer-Moore算法进行改进。对于本题的描述，最终结果元素个数至多为 2 个，因为如果大于等于三个，总数就会超过 n。那么我们可以设置两个候选者，根据Boyer-Moore算法进行改进，设置 candidate1 = nums[0] 和 candidate2 = nums[0]，count1 = 0 和 count2 = 0。然后遍历数组，如果当前元素等于 candidate1 ，则 count1++。如果当前元素等于 candidate2 ，则 count2++。如果都不等，则先检查 count1 和 count2 是否为0（如果先对 count1 和 count2 进行减 1 操作的话，而非检测是否为 0，会出现 count1 和 count2 为负数的情况，显然这不符合题意）。如果 count1 = 0 则将 candidate1 更新为当前元素，然后 count1 + 1。如果 count2 = 0 则将 candidate2 更新为当前元素，然后 count2 + 1。如果 count1 和 count2 都不为 0，则将 count1 和 count2 进行减 1 操作。当最后选出两个候选元素后（其实是选出出现次数最多的两个元素），还需要判断其出现的次数是否满足要求，那么只需在遍历一次数组就可以统计出两个候选元素的出现次数，若满足则加入到结果数组中。  


## Code-1
```
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
```

## Code-2
```
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
```

## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

