class Solution {
public:
    int romanToInt(string s) {
        int n = s.size(), result = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == 'I') result += 1;
            if(s[i] == 'V'){
                result += 5;
                if(i > 0 && s[i - 1] == 'I'){
                    result -= 1;
                    i--;
                }
            }
            if(s[i] == 'X'){
                result += 10;
                if(i > 0 && s[i - 1] == 'I'){
                    result -= 1;
                    i--;
                }
            }
            if(s[i] == 'L'){
                result += 50;
                if(i > 0 && s[i - 1] == 'X'){
                    result -= 10;
                    i--;
                }
            }
            if(s[i] == 'C'){
                result += 100;
                if(i > 0 && s[i - 1] == 'X'){
                    result -= 10;
                    i--;
                }
            }
            if(s[i] == 'D'){
                result += 500;
                if(i > 0 && s[i - 1] == 'C'){
                    result -= 100;
                    i--;
                }
            }
            if(s[i] == 'M'){
                result += 1000;
                if(i > 0 && s[i - 1] == 'C'){
                    result -= 100;
                    i--;
                }
            }
        }
        return result;
    }
};