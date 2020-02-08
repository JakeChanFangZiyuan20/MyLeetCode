# LeetCode-363-Max Sum of Rectangle No Larger Than K-矩形区域不超过 K 的最大数值和

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/363.png)


## 综述：  
\+ 本题参考了题解。  
\+ 该题有一个基础就是[LeetCode53.最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)使用结合set来a的的基础。
\+ 对于获得子矩形的值和，可以先构建整个矩形的前缀和矩阵，也就是presum[0][0] = a[0][0], presum[i][j] = a[i][1] + a[i][2] + ... + a[i][j - 1] n为列数，其中presum也可以在每一行的第一个元素先赋值0。那么，在计算一个矩形和时，只需定义好左右（l，r）边界，然后计算每一行的和，假设有f行，则每一行有一个值(假设在第i行presum[i][r] - presum[i][l - 1])，共有f个值，可看成一个新数组NewPreSum。这个操作相当于降维。那么假设计算第x行到y行的矩阵值的和则为sum = NewPreSum[y] - NewPreSum[x - 1]。按照题目要求，要找到矩阵值和尽可能靠近$k$，即sum = NewPreSum[y] - NewPreSum[x - 1] 小于等于 k，也为NewPreSum[y] - k 小于等于 NewPreSum[x - 1] ，意为在NewPreSum[y]前面的值找一个大于NewPreSum[y] - k的最小值，记为lower，那么如同[LeetCode53.最大子序和](https://leetcode-cn.com/problems/maximum-subarray/)使用结合set来a的的基础。中一样，用set（自动排序）来存储NewPreSum[y]之前的值，由于set有一个lower_bound(val)的函数，用于找到大于val的最小值，所以这里用set。若找到这样一个lower值，然后NewPreSum[y] - lower肯定小于等k，那么只需和结果值（可以先设为INT_MIN）比较，取最大更新结果值就可以找到小于k距离k最近的值。还需要把NewPreSum[y]放入set中，因为当前NewPreSum[y]相当于之后的NewPreSum[x - 1]。  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/363-1.png)


## Code
```
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>>pre(m, vector<int>(n + 1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 1; j <= n; j++){
                pre[i][j] = pre[i][j - 1] + matrix[i][j - 1];
            }
        }
        int result = INT_MIN;
        for(int left = 1; left <= n; left++){
            for(int right = left; right <= n; right++){
                set<int>NumSet;
                NumSet.insert(0);
                int curSum = 0;
                for(int i = 0; i < m; i++){
                    int preSum = pre[i][right] - pre[i][left - 1];
                    curSum += preSum;

                    set<int>::iterator iter = NumSet.lower_bound(curSum - k);
                    if(iter != NumSet.end()) result = max(result, curSum - *iter);
                    NumSet.insert(curSum);
                }
            }
        }
        return result;
    }
};
```


## 复杂度分析
m为矩阵行数，n为矩阵列数
空间复杂度O(mn)  
时间复杂度O(mnlogn)，set的插入操作O(longn)

