# LeetCode-27-Remove Element-移除元素

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/27.png)

## 综述：  
\+ 该题解法同[LeetCode26.删除排序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)有相似之处。  
\+ 遍历每一个元素i，当nums[i]不等于target时，len++，当nums[i]=target时，使用第二个指针j，j=i+1开始向右开始遍历，若nums[j]不等于target时，交换nums[i]和nums[j]，然后len++，并break掉j的遍历。

## Code
```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if(n == 0) return 0;

        int len = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == val){
                for(int j = i + 1; j < n; j++){
                    if(nums[j] != val){
                        swap(nums[i], nums[j]);
                        len++;
                        break;
                    }
                }
            } else{
                len++;
            }
        }
        return len;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

