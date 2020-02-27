class Solution {
private:
    unordered_map<char, string>button = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string>result;
    string newGroup;
    int digitsLen;
    string digits;
public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        digitsLen = digits.size();

        DFS(0);

        return result;
    }

    void DFS(int pos){
        if(pos == digitsLen) return ;
        if(pos == digitsLen - 1){
            for(int i = 0; i < button[digits[pos]].size(); i++){
                newGroup.push_back(button[digits[pos]][i]);
                result.push_back(newGroup);
                newGroup.pop_back();
            }
            return ;
        }
        for(int i = 0; i < button[digits[pos]].size(); i++){
            newGroup.push_back(button[digits[pos]][i]);
            DFS(pos + 1);
            newGroup.pop_back();
        }
    }
};