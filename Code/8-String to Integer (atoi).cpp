class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        if(n == 0) return n;

        long result = 0, flag = 0; // flag = 0, result is positive
        int i = 0;

        // discard whitespace character
        for(i; i < n; i++){
            if(str[i] == ' ') continue;
            else break;
        }

        if(i == n && (str[i] < '0' || str[i] > '9') && 
                str[i] != '-' && str[i] != '+'){ 
            return 0;
        }

        if(str[i] == '+'){
            i++;
        } else if(str[i] == '-'){
            flag++;
            i++;
        }

        for(i; i < n; i++){
            if(str[i] < '0' || str[i] > '9') break;

            result = result * 10 + str[i] - 48;
            if(flag == 0 && result >= 2147483647) return INT_MAX;
            else if(flag == 1 && result >= 2147483648) return INT_MIN;
        }

        if(flag) result = -result;

        return result;
    }
};