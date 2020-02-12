class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // m 行，n 列
        int m = grid.size(), n = grid[0].size();
        
        if(m == 0 && n == 0) return 0;
        if(m == 1 && n == 1) return grid[0][0];
        
        // 第一行处理
        for(int i = 1; i < n; i++){
            grid[0][i] += grid[0][i - 1];
        }   
        
        // 第一列处理
        for(int i = 1; i < m; i++){
            grid[i][0] += grid[i - 1][0];
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        
        return grid[m - 1][n - 1];
    }
};