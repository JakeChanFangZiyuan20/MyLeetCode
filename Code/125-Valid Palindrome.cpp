class Solution {
public:
    bool isPalindrome(string s) {
        int strSize = s.size();
        if(strSize == 0) return true;

        string str1(""), str2("");
        for(int i = 0; i < strSize; i++){
            if(('0' <= s[i] && s[i] <= '9') || ('a' <= s[i] && s[i] <= 'z')){
                str1.push_back(s[i]);
            } else if('A' <= s[i] && s[i] <= 'Z'){
                str1.push_back(s[i] + 32);
            }
        }

        str2 = str1;
        reverse(str2.begin(), str2.end());

        if(str1 == str2) return true;

        return false;
    }
};