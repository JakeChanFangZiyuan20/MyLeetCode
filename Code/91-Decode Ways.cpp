class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0 || s[0] == '0') return 0;

        string cur;
        int a = 1, b = 1, c = b, curInt;
        for(int i = 1; i < n; i++){
            if(s[i] == '0'){
                if(s[i - 1] != '2' && s[i - 1] != '1') return 0;
                else{
                    b = a;
                    continue;
                }
            }
            if(s[i - 1] == '0') continue;
            cur = string({s[i - 1], s[i]});
            curInt = stoi(cur);
            if(s[i - 1] != '0' && 1 <= curInt && curInt <= 26) c = a + b;
            else c = b;
            a = b;
            b = c;
        }
        return b;
    }
};