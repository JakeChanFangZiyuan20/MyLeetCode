class Solution {
public:
    int lengthOfLastWord(string s) {
        int strSize = s.size();
        if(strSize == 0) return strSize;

        int count = 0;
        for(int i = strSize - 1; i >= 0; i--){
            if(s[i] == ' ') continue;
            else{
                int j = i;
                for( ; j >= 0; j--){
                    if(s[j] >= 'a' && s[j] <= 'z' || s[j] >= 'A' && s[j] <= 'Z'){ 
                        count++;
                    } else{
                        return count;
                    }
                }
                if(j == -1) return count;
            }
        }

        return 0;
    }
};