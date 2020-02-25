class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 0 || numRows == 1) return s;

        int n = s.size();
        if(n <= numRows) return s;
        vector<string>resultPart(numRows);
        int row = 0, flag = 1;
        for(int i = 0; i < n; i++){
            resultPart[row].push_back(s[i]);
            if(flag == 1) row++;
            else if(flag == 2) row--;
            if(row == numRows){
                flag = 2;
                row -= 2;
            } else if(row == -1){
                flag = 1;
                row += 2;
            }
        }
        
        for(int i = 1; i < numRows; i++){
            resultPart[0] += resultPart[i];
        }
        return resultPart[0];
    }
};