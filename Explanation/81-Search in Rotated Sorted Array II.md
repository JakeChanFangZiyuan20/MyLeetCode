# LeetCode-81-Search in Rotated Sorted Array II-搜索旋转排序数组 II

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/81.png)

## 综述：  
\+ 本题一开始思考不到位，尝试了一下即刻认为不能使用二分找旋转点，使用了O(n)的方法，但参考了题解后发现实际上是可以的（while(true){ 打左脸; 打右脸; }）。  
\+ 在[LeetCode33.搜索旋转排序数组](https://leetcode-cn.com/problems/search-in-rotated-sorted-array/)的基础上，本题难点在于类似“222222022”这种情况，这种情况下 nums[left] = nums[middle] = nums[right]，无法判断左右部分哪边有序，但可以使用 left++ 这一操作就可以解决。所以还是先找旋转点，找不到直接二分查找，找到则左右两部分二分查找。

## Code
```
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        if(nums.size() == 1) {
            if(nums[0] == target) return true;
            else return false;
        }

        int n = nums.size();

        // 先寻找旋转点
        bool hasRotatePoint = false;
        int left = 0, right = n - 1;
        while(left < right){
            if(nums[left] == target) return true;
            if(nums[right] == target) return true;

            int middle = (left + right) / 2;
            if(nums[middle] == target) return true;

            if(nums[middle] == nums[left]){
                left++;
                continue;
            }

            if(nums[middle] <= nums[right]) right = middle;
            else left = middle;
            if(left + 1 == right) break;
        }
        //cout << left << ',' << right;

        // 查找target值
        if(nums[left] <= nums[right]){ // 数组旋转后仍有序
            int a = 0, b = n - 1;
            while(a < b){
                if(nums[a] == target) return true;
                if(nums[b] == target) return true;

                int middle = (a + b) /2;
                if(nums[middle] == target) return true;

                if(nums[middle] < target) a = middle;
                if(nums[middle] > target) b = middle;
                if(a + 1 == b) break;
            }
        } else{
            int a, b;
            if(nums[0] <= target && target <= nums[left]){
                a = 0;
                b = left;
            } else if(nums[right] <= target && target <= nums[n - 1]){
                a = right;
                b = n - 1;
            } else{
                return false;
            }
            while(a < b){
                if(nums[a] == target) return true;
                if(nums[b] == target) return true;

                int middle = (a + b) /2;
                if(nums[middle] == target) return true;

                if(nums[middle] < target) a = middle;
                if(nums[middle] > target) b = middle;
                if(a + 1 == b) break;
            }
        }

        return false;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(logn)

