class Solution {
public:
    int findLUSlength(string a, string b) {
        short str1Len = a.size(), str2Len = b.size();
        if(str1Len != str2Len) return max(str1Len, str2Len);
        else{
            if(a == b) return -1;
            else return str1Len;
        }
        return -1;
    }
};