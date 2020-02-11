class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return ;

        // n 为行列数
        int n = matrix.size();
        
        // 矩阵转置
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 矩阵左右翻转
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n / 2; j++){
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
    }
};