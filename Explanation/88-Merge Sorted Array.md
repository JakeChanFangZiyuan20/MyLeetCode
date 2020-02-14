# LeetCode-88-Merge Sorted Array-合并两个有序数组

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/88.png)

## 综述：  
\+ 归并排序中的数组合并。

## Code
```
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>mergeNums(nums1.size(), 0);
        int i = 0, j = 0, k = 0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j]){
                mergeNums[k++] = nums1[i++];
            } else{
                mergeNums[k++] = nums2[j++];
            }
        }
        while(i < m){
            mergeNums[k++] = nums1[i++];
        }
        while(j < n){
            mergeNums[k++] = nums2[j++];
        }

        nums1 = mergeNums;
    }
};
```


## 复杂度分析
空间复杂度O(k)，k 为 num1 数组元素个数  
时间复杂度O(m+n)

