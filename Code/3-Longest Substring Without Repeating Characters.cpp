class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0 || n == 1) return n;

        int maxLen = 1, slow = 0, fast = 1;
        unordered_map<char, int>cMap;

        cMap[s[slow]] = slow;
        for(int i = 1; i < n; i++){
            if(cMap.count(s[i]) == 0){
                cMap[s[i]] = -1;
            }
        }
        if(cMap.size() == 1) return 1;

        for(; fast < n; fast++){
            if(cMap[s[fast]] == -1){
                cMap[s[fast]] = fast;
            } else{
                maxLen = max(maxLen, fast - slow);
                if(maxLen == cMap.size()) return maxLen;

                int pos = cMap[s[fast]];
                for(slow; slow <= pos; slow++){
                    cMap[s[slow]] = -1;
                }
                cMap[s[fast]] = fast;
            }
        }
        maxLen = max(maxLen, fast - slow);

        return maxLen;
    }
};