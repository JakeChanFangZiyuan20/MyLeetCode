class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // m 行，n 列
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(m == 0 && n == 0 || obstacleGrid[0][0] == 1) return 0;
        
        vector<vector<long>>matrix(m, vector<long>(n, 0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(obstacleGrid[i][j] == 1){
                    matrix[i][j] = 1;
                }
            }
        }

        // 第一行更改
        for(int i = 0; i < n; i++){
            if(matrix[0][i] == 1){
                for(int j = i; j < n; j++){
                    matrix[0][j] = 0;
                }
                break;
            } else{
                matrix[0][i] = 1;
            }
        }

        // 第一列更改m
        for(int i = 1; i < m; i++){
            if(matrix[i][0] == 1){
                for(int j = i; j < m; j++){
                    matrix[j][0] = 0;
                }
                break;
            } else{
                matrix[i][0] = 1;
            }
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 1){
                    matrix[i][j] = 0;
                    continue;
                }

                long up = matrix[i - 1][j], left = matrix[i][j - 1];
                matrix[i][j] = up + left;
            }
        }
        return matrix[m - 1][n - 1];
        //return 0;
    }
};