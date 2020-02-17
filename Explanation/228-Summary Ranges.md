# LeetCode-228-Summary Ranges-汇总区间

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/228.png)

## 综述：  
\+ 从左到右扫描数组提取区间。  

## Code
```
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) return vector<string>();

        vector<string>result;
        int n = nums.size();
        string newRanges(to_string(nums[0]));

        if(n == 1){
            result.push_back(newRanges);
            return result;
        }

        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i - 1] + 1){

                if(to_string(nums[i - 1]) != newRanges){
                    newRanges += "->";
                    newRanges += to_string(nums[i - 1]);
                }

                result.push_back(newRanges);
                newRanges = "";
                newRanges += to_string(nums[i]);
            }
        }

        if(nums[n - 1] == nums[n - 2] + 1){
            newRanges += "->";
            newRanges += to_string(nums[n - 1]);
        } 
        result.push_back(newRanges);
        
        return result;
    }
};
```


## 复杂度分析
空间复杂度O(n)  
时间复杂度O(n)

