class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return vector<int>(1, 1);

        vector<int>result(rowIndex + 1, 1);
        if(result.size() > 2){
            for(int i = 3; i <= rowIndex + 1; i++){
                for(int j = i - 2; j > 0; j--){
                    result[j] += result[j - 1]; 
                }
            }
        }

        return result;
    }
};