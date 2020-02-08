class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        // m 为矩阵行数，n 为矩阵列数
        // 构造前缀和矩阵
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>>pre(m, vector<int>(n + 1, 0));
        for(int i = 0; i < m; i++){
            for(int j = 1; j <= n; j++){
                pre[i][j] = pre[i][j - 1] + matrix[i][j - 1];
            }
        }
        int result = INT_MIN; // 结果值
        for(int left = 1; left <= n; left++){ // 左边界
            for(int right = left; right <= n; right++){ // 右边界
                set<int>NumSet;
                NumSet.insert(0);
                int curSum = 0; // 记录前缀和
                for(int i = 0; i < m; i++){ // 遍历行计算左右边界内值和的前缀和以及矩阵值和
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