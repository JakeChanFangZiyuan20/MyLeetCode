class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.size() == 0 || s.size() == 1) return s;
        map<char, int>counts;
        map<char, int>counts2;
        for(char c = 'a'; c <= 'z'; c++){
            counts[c] = 0;
            counts2[c] = 0;
        }
        for(string::iterator iter = s.begin(); iter != s.end(); iter++){
            counts[*iter]++;
        }

        string CStack;
        for(string::iterator iter = s.begin(); iter != s.end(); iter++){
            if(counts2[*iter] == 1){
                counts[*iter]--;
                continue;
            } else if(CStack.size() == 0 || *iter > *(CStack.end() - 1)){
                CStack.push_back(*iter);
                counts2[*iter] = 1;
            } else if(*iter < *(CStack.end() - 1)){
                if(counts[*(CStack.end() - 1)] > 1){
                    counts[*(CStack.end() - 1)]--;
                    counts2[*(CStack.end() - 1)] = 0;
                    CStack.erase(CStack.end() - 1);
                    iter--;
                } else{
                    CStack.push_back(*iter);
                    counts2[*iter] = 1;
                }
            }
        }
        return CStack;
    }
};