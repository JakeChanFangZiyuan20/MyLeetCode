# LeetCode-41-First Missing Positive-缺失的第一个正数

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/41.png)

## 综述：  
\+ 该题参考了题解。  
\+ 从左向右遍历数组，检测当前 nums[i] <= 0 则跳过，若满足 nums[i] != i + 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i] ，则进行交换 swap(nums[nums[i] - 1], nums[i]) 并 i 留在当前，即 i--。  
\+ 说明：所找的那个缺失的正数一定小于等于 n + 1，n 为数组长度。对于上面做法，是将 i 位置上的数放置 i + 1，并可认为 i 位置上的数放置 i + 1 是一种可取状态，所以遍历的时候需要检测 nums[i] != i + 1 。  
\+ 若当前 i 位置内的元素不为 i + 1，即 nums[i] != i + 1 ，则可以将当前 nums[i] 放到下标 nums[i] - 1 内，但还需要检测满足 nums[i] <= n，才可以进行两个位置的数值交换，即当前位置 i 和 位置 nums[i] - 1 这两个位置的交换。同时如果同时满足了 nums[i] != i + 1 && nums[i] <= n，则满足一定的交换条件，还需要检测位置 nums[i] - 1 的元素是否已经是 nums[i]，若是，则不交换，当前位置 i++，若否则交换。  
\+ 当所有数据交换完位置，先设置 result = n + 1，n 为数组长度，然后从左向右遍历数组，如果遇到第一个 nums[i] != i + 1，则将 result 更新为 i + 1，并返回result。若 result 一直没有被更新，则证明，交换完位置后的数组符合下标 0 到 n - 1，数据为 1 到 n，那么缺少的是 n + 1，由于result 在进入更新检测前已赋值为 n + 1，所以可以直接返回 result。  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/41-1.png)
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/41-2.png)
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/41-3.png)
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/41-4.png)
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/41-5.png)
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/41-6.png)

## Code
```
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 1;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0 &&nums[i] != i + 1 && nums[i] <= n 
                    && nums[nums[i] - 1] != nums[i]){
                swap(nums[nums[i] - 1], nums[i]);
                i--;
            }
        } 
        int result = n + 1;
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1) {
                result = i + 1;
                break;
            }
        }
        return result;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

