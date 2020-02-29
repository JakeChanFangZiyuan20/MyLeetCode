// 方法一
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        if(len == 0) return false;

        bool result = false;
        string sub, rebuild;
        int subLen, times;
        for(int i = 0; i < len; i++){
            sub = s.substr(0, i + 1);
            subLen = sub.size();

            if(subLen > len / 2) break;

            if(len % subLen == 0){
                times = len / subLen;
                rebuild = "";
                while(times--){
                    rebuild += sub;
                }
                if(rebuild == s) return true;
            }
        }
        return result;
    }
};

// 方法二
/*
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 0) return false;
        string t = s + s;
        t = t.substr(1, 2 * s.size() - 2);
        if(t.find(s) == -1) return false;
        return true; 
    }
};
*/