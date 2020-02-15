# LeetCode-53-Maximum Subarray-最大子序和

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/2.png)


## 综述：  
\+ 本题参考了题解。  
\+ 方法一：  
\+ 设所给数组为a，先构造一个前缀序列presum，即presum[0] = a[0], presum[i] = a[1] + a[2] + ... + a[i - 1]  
\+ 当计算 a[1] + a[2] + ... + a[i - 1] 时，只需sum = presum[j] - presum[i - 1]（在构造前缀数组时可先将0放入，即presum[0] = 0，presum[1] = a[0]）  
\+ 按照题目要求，需要找到max(sum)。由于从左开始遍历presum，当前为presum[j]。要使得sum最大，则presum[i - 1]要最小，即需要再当前数值前找到一个最小的数值，所以我们可以用set来存储presum[j]之前的值，因为set会自动将存入的数值排序。故每遍历到前缀数组的一个数值，然后返回set中begin值，相减后和maxS比较，若大于则更新maxS，然后将当前presum[j]放入set中。  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/53-1.png)
  
\+ 方法二：  
\+ 贪心算法：  
\+ 对于所给的序列，其中包含多个不连续非值最大的子序列。每遍历到一个值，若其之前的子序列小于0，则这个之前的子序列加到当前值只会让所构成的新的子序列和值更小，那么需要更新之前的子序列。若之前的子序列和值大于0，则当前数值加上之前的子序列和值会让子序列值增大，所以不需更新之前的子序列值。  

## Code-1
```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int maxSum = -2147483648;
        // 构造前缀数组
        for(int i = 1; i < nums.size(); i++){
            nums[i] += nums[i - 1];
        }

        //
        set<int>Set;
        Set.insert(0);
        for(int i = 0; i < nums.size(); i++){
            int curMax = nums[i] - *Set.begin();
            maxSum = max(maxSum, curMax);
            Set.insert(nums[i]);
        }
        return maxSum;
    }
};

```

## Code-2
```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int preSum = 0, maxSum = 0;
        preSum = maxSum = nums [0];
        for(int i = 1; i < nums.size(); i++){
            if(preSum < 0) preSum = nums[i];
            else{
                preSum += nums[i];
            }
            maxSum = max(maxSum, preSum);
        }
        return maxSum;
    }
};

```

## 复杂度分析
\+ 方法一  
空间复杂度O(n)  
时间复杂度O(nlogn)，set的插入操作O(logn)

\+ 方法二  
空间复杂度O(1)  
时间复杂度O(n)

