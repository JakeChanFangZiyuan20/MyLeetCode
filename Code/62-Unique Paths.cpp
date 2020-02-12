class Solution {
public:
    int uniquePaths(int m, int n) {
        // n 行，m 列
        if(n == 0 && m == 0) return 0;
        if(n == 1 || m == 1) return 1;

        vector<vector<int>>matrix(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || j == 0){
                    matrix[i][j] = 1;
                    continue;
                }
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            }
        }
        return matrix[n - 1][m - 1];
    }
};