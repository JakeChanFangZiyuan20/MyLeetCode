# LeetCode-26-Remove Duplicates from Sorted Array-删除排序数组中的重复项

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/1.png)

## 综述：  
\+ 该题最直接的想法就是直接用vector中的erase，但会用时很长。这里的Code-1和Code-2  
\+ 如果仔细琢磨题目所给的信息，会发现不需要erase，只需将出现过的不同的数值复制到所给vector前面部分就行了。  
\+ 然后就是使用双指针方法。这里的Code-3

## Code-1
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();

        for(vector<int>::iterator iter = nums.begin(); iter != nums.end() - 1; ){
            if(*iter == *(iter + 1)) {
                nums.erase(iter);
            } else{
                iter++;
            }
        }

        return nums.size();
    }
};
```

## Code-2
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();

        for(vector<int>::iterator iter1 = nums.begin(); iter1 != nums.end() - 1; ){
            if(*(iter1 + 1) == *iter1){
                vector<int>::iterator iter2 = iter1 + 1;
                while(iter2 != nums.end() && *iter2 == *iter1) iter2++;
                iter1 = nums.erase(iter1 + 1, iter2);
                if(iter1 == nums.end()) return nums.size();
            } else{
                iter1++;
            }
        }

        return nums.size();
    }
};
```

## Code-3
```
// 第三版
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();

        int i = 0, n = nums.size();
        for(int j = 1; j < n; j++){
            if(nums[j] != nums[i]){
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

