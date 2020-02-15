class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0) return vector<vector<int>>();

        vector<vector<int>>result;

        for(int i = 1; i <= numRows; i++){
            vector<int>newRow(i, 1);
            if(i > 2){
                for(int j = 1; j < newRow.size() - 1; j++){
                    newRow[j] = (*(result.end() - 1))[j] + (*(result.end() - 1))[j - 1];
                }
            }
            result.push_back(newRow);
        }

        return result;
    }
};