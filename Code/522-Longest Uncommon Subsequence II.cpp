class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int maxLen = -1;
        for(int i = 0; i < strs.size(); i++){
            int j = 0;
            for( ; j < strs.size(); j++){
                if(j == i) continue;
                if(isSubStr(strs[i], strs[j])){
                    break;
                }
            }
            if(j == strs.size()){
                maxLen = max(maxLen, (int)strs[i].size());
            }
        }
        return maxLen;
    }

    bool isSubStr(string str1, string str2){
        int i = 0, j = 0;
        for( ; i < str1.size() && j < str2.size(); j++){
            if(str1[i] == str2[j]){
                i++;
            }
        }
        if(i == str1.size()) return true;
        return false;
    }
};