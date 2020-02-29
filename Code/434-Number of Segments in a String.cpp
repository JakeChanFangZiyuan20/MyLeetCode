class Solution {
public:
    int countSegments(string s) {
        int len = s.size();
        int result = 0;
        for(int i = 0; i < len; i++){
            if(s[i] != ' '){
                int j = i;
                while(j < len && s[j] != ' '){
                    j++;
                }
                result++;
                i = j--;
            }
        }
        return result;
    }
};
