class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.size();
        if(len == 0) return -1;
        if(len == 1) return 0;

        unordered_map<char, vector<int>>sMap;
        for(int i = 0; i < len; i++){
            auto iter = sMap.find(s[i]);
            if(iter == sMap.end()){
                sMap.insert({s[i], vector<int>(1, i)});
            } else{
                (iter->second).push_back(i);
            }
        }

        int prePos = -1;
        for(auto iter = sMap.begin(); iter != sMap.end(); iter++){
            if((iter->second).size() == 1){
                if(prePos == -1) prePos = (iter->second)[0];
                else prePos = min(prePos, (iter->second)[0]);
            }
        }

        return prePos;
    }
};