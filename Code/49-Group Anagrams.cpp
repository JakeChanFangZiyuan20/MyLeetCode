class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return vector<vector<string>>();

        string temp;
        unordered_map<string, vector<string>>strsMap;
        for(int i = 0; i < n; i++){
            temp = strs[i];
            sort(temp.begin(), temp.end());

            auto iter = strsMap.find(temp);
            if(iter != strsMap.end()){
                (iter->second).push_back(strs[i]);
            } else{
                strsMap.insert({temp, vector<string>(1, strs[i])});
            }
        }

        vector<vector<string>>result;
        for(auto iter = strsMap.begin(); iter != strsMap.end(); iter++){
            result.push_back(iter->second);
        }

        return result;
    }

};