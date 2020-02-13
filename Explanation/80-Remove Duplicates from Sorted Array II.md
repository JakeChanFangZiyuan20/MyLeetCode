# LeetCode-80-Remove Duplicates from Sorted Array II-删除排序数组中的重复项 II

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/80.png)

## 综述：  
\+ 该题主要解法使用双指针。  
\+ 若所给数组的大小为 0、1、2，则直接返回数组大小，因为无论在任何情况都满足元素重复次数小于等于2。  
\+ 此处做法，先用 i 做为探路指针，从左第一个元素开始向右遍历，遇到不满足 nums[i] == nums[i + 1] && nums[i + 2] == nums[i] 时，直接 i++。若满足时则开始使用第二个指针 j。j 向从 i + 1 开始向右走，直到 nums[j] != nums[i]。此时从 j 位置开始替换 i 后面的值，当满足 nums[j] == nums[i] && nums[j] == nums[i - 1] 时，则先 i + 1，然后将位置 j 的值赋给位置 i，即 nums[++i] = nums[j]。重复，直到结尾。然后需要返回结果就是 i + 1。  
\+ 按照上述做法会有一个特殊情况就是：假设有 n 个元素，从位置 0 到 n - 3 的元素都符合重复次数小于等于2。如果仍按照上述做法，当 i 走到位置 n - 2 并进行 nums[i] == nums[i + 1] && nums[i + 2] == nums[i] 判断时，会出现越界，所以这里可以设置判断 i 在 n - 2 时，直接返回所给数组的大小，因为从位置 0 到 n - 3 的元素都符合重复次数小于等于2，并且剩余的最后两个元素无论什么情况都会符合元素重复次数小于等于2，所以可以直接返回所给数组的大小，更何况在这种情况下，数组并没有任何改变。

## Code
```
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1 || nums.size() == 2){
            return nums.size();
        }

        int n = nums.size(), result;
        for(int i = 0; i < n; ){
            if(i == n - 2){
                result = n;
                break;
            }else if(nums[i] == nums[i + 1] && nums[i + 2] == nums[i]){
                i++;
                int j;
                for(j = i + 1; j < n; j++){
                    if(nums[j] != nums[i]){
                        break;
                    }
                }
                for(j; j < n; j++){
                    if(nums[j] == nums[i] && nums[j] == nums[i - 1]){
                        continue;
                    }
                    nums[++i] = nums[j];
                }
                result = i + 1;
                break;
            }
            else{
                i++;
            }
        }
        
        return result;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

