# LeetCode-33-Search in Rotated Sorted Array-搜索旋转排序数组

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/33.png)

## 综述：  
\+ 看到题目要求算法时间复杂度必须是 O(log n) 级别，很容易想到二分。  
\+ 按照题目，旋转后的数组可以保持不变或者按照旋转点分成两部分，前部分数字均大于后部分。所以可以分成两个情况来处理  
\+ 情况一：旋转后数组仍有序。这种情况找target值直接二分。  
\+ 情况二：先寻找旋转点。使用二分，若中点处数值小于右界数值，证明中点到右界有序，则将右界更新到中点处，若中点处数值大于右界数值，证明左界数值到中点处数值有序，则将左界更新到中点处。重复，直到左界在右界左方，并位置相差1。则左部分为 0 到 left，右部分为 right 到 n-1。然后将确定target是在左部分还是右部分，确定方法：target和nums[0]比较，若大于则在左部分。若target比nums[n-1]小，则在右部分。确定了左还是右部分，则同情况一一样了，在当前确定的部分继续二分查找。  
\+ 注意：  
\+ &emsp;在情况一中，若target小于nums[0] 或target大于nums[n - 1]都是没有意义的，直接返回-1。  
\+ &emsp;每确定了left、right、middle下标，立刻检测对应nums中的值是否等于target，若等于立刻返回下标。  

## Code
```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return -1;
        if(n == 1){
            if(nums[0] == target) return 0;
            else return -1;
        }

        int pos = -1;
        if(nums[0] < nums[n - 1]){ // 旋转后的数组有序
            if(target < nums[0] || target > nums[n - 1]){ // 特殊情况
                return -1;
            }

            int left = 0, right = n - 1;
            while(left < right){
                if(nums[left] == target) return left;
                if(nums[right] == target) return right;

                int middle = (left + right) / 2;
                if(nums[middle] == target) return middle;
                else if(nums[middle] < target ){
                    left = middle;
                } else if(nums[middle] > target){
                    right = middle;
                }
                if(left + 1 == right) break;
            }
        } else{ // 旋转后非有序
            //  寻找旋转点
            int left = 0, right = n - 1;
            while(left < right){
                if(nums[left] == target) return left;
                if(nums[right] == target) return right;

                int middle = (left + right) / 2;
                if(nums[middle] == target) return middle;

                if(nums[middle] < nums[right]){
                    right = middle;
                } else{
                    left = middle;
                }

                if(left + 1 == right) break;
            }
            //cout << left << ',' << right << endl;;

            if(target > nums[0]){ // 0 到 left
                int a = 0, b = left;
                while(a < b){
                    if(nums[a] == target) return a;
                    if(nums[b] == target) return b;

                    int middle = (a + b) / 2;
                    //cout << nums[middle] << endl;
                    if(nums[middle] == target) return middle;
                    else if(nums[middle] < target){
                        a = middle;
                    } else{
                        b = middle;
                    }
                    
                    if(a + 1 == b) break;
                }
            } else if(target < nums[n - 1]){ // right 到 n-1
                int a = right, b = n - 1;
                while(a < b){
                    if(nums[a] == target) return a;
                    if(nums[b] == target) return b;

                    int middle = (a + b) / 2;
                    if(nums[middle] == target) return middle;
                    else if(nums[middle] < target){
                        a = middle;
                    } else{
                        b = middle;
                    }

                    if(a + 1 == b) break;
                }
            }
        }

        return pos;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(logn)

