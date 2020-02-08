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