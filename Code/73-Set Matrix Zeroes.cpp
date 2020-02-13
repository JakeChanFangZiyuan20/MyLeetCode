class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return ;
        int m = matrix.size(), n = matrix[0].size();
        set<int>rowSet, colSet;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    rowSet.insert(i);
                    colSet.insert(j);
                }
            }
        }
        for(set<int>::iterator iter = rowSet.begin(); iter != rowSet.end(); iter++){
            int curRow = *iter;
            for(int j = 0; j < n; j++){
                matrix[curRow][j] = 0;
            }
        }
        for(set<int>::iterator iter = colSet.begin(); iter != colSet.end(); iter++){
            int curCol = *iter;
            for(int i = 0; i < m; i++){
                matrix[i][curCol] = 0;
            }
        }
    }
};