# LeetCode-414-Third Maximum Number-第三大的数

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/414.png)

## 综述：  
\+ 方法一：使用函数先将数组排序，但复杂度为O(nlogn)，不符合题意  
\+ 先将所给数组排序，然后从后往前遍历。将最后一个元素设为最小值，然后设置一个计数器（初始值为 1 ），再从倒数第二个数开始遍历，若发现当前元素小于最小值，更新最小值并将计数器 +1 ，计数器每加一次判断是否为 3，若是则返回当前元素。若没有第三大的数，则最终返回最后一个元素（因为已排序）。

\+ 方法二：使用 set  
\+ 因为 set 具有排序和不重复插入元素的以及插入时间复杂度 O(logn) 的特点，所以可以将元素插入 set 中，然后找到第三大。但此方法空间复杂度为 O(n)。  

\+ 方法三：使用 set ，但 set.size 大小维护在 3 
\+ 维护一个大小为 3 的 set 的同时，维护一个最大值，该最大值可用于当整个数组不同元素小于 3 时可直接返回。遍历每一个元素，如果该元素不在 set 内，则判断 set 的大小，如果小于 3，则该元素直接入 set ，如果大于，则判断当前元素是否大于 set 中第一个元素，如果大于，则将 set 中第一个元素删除，然后插入当前元素。最终只需返回 set 的第一个元素即可。这个方法是在方法二上进行改进，使得空间复杂度为 O(1)。  

## Code-1
```
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), minNum = nums[n - 1], count = 1;
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < minNum){
                minNum = nums[i];
                count++;
                if(count == 3) return nums[i];
            }
        }
        return nums[n - 1];
    }
};
```

## Code-2
```
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int>numsSet;
        int n = nums.size(), maxNum = nums[0];
        numsSet.insert(nums[0]);
        for(int i = 1; i < n; i++){
            numsSet.insert(nums[i]);
            if(nums[i] > maxNum) maxNum = nums[i];
        }
        int result;
        if(numsSet.size() < 3) result = maxNum;
        else{
            int count = 0;
            for(auto iter = numsSet.begin(); iter != numsSet.end(); iter++){
                count += 1;
                if(count == numsSet.size() - 2){
                    result = *iter;
                    break;
                }
            }
        }
        return result;
    }
};
```

## Code-3
```
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size(), maxNum = nums[0];
        set<int>numsSet; numsSet.insert(nums[0]);

        for (int i = 1; i < n; i++) {
            if (nums[i] > maxNum) maxNum = nums[i];

            if (numsSet.find(nums[i]) == numsSet.end()) {
                if (numsSet.size() < 3) {
                    numsSet.insert(nums[i]);
                }
                else if (nums[i] > * numsSet.begin()) {
                    numsSet.erase(numsSet.begin());
                    numsSet.insert(nums[i]);
                }
            }
        }

        int result;
        if (numsSet.size() < 3) result = maxNum;
        else result = *numsSet.begin();
        return result;
    }
};
```

## 复杂度分析
方法一：  
空间复杂度O(1)  
时间复杂度O(nlogn)  

方法二：  
空间复杂度O(n)  
时间复杂度O(n)  

方法三：  
空间复杂度O(1)  
时间复杂度O(n)  

