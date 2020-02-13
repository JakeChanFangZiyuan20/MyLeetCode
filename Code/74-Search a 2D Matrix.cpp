class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;

        // m 行，n 列
        int m = matrix.size(), n = matrix[0].size();

        // 锁定行
        int row = -1;
        for(int i = 0; i < m; i++){
            if(matrix[i][0] <= target && target <= matrix[i][n - 1]){
                row = i;
                break;
            }
        }

        if(row != -1){
            int left = 0, right = n - 1;
            if(matrix[row][left] == target) return true;
            if(matrix[row][right] == target) return true;
            while(left < right){
                int middle = (left + right) / 2;
                if(matrix[row][middle] == target) return true;

                if(matrix[row][middle] < target) left = middle;
                else right = middle;

                if(matrix[row][left] == target) return true;
                if(matrix[row][right] == target) return true;

                if(left + 1 == right) break;
            }
        }

        return false;
    }
};