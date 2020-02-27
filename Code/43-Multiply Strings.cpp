class Solution {
public:
    string multiply(string num1, string num2) {
        int str1Size = num1.size(), str2Size = num2.size();
        if(str1Size == 0 || str2Size == 0) return "";
        if(num1[0] == '0' || num2[0] == '0') return "0";

        string result(""), curResult;
        for(int i = 0; i < str2Size; i++){
            curResult = OneMultiBig(num2[i] - 48, num1);
            result = add(curResult, result);
            if(i < str2Size - 1) result += "0";
        }

        return result;
    }

    string OneMultiBig(int one, string big){
        if(one == 0) return "0";

        int flag = 0, strSize = big.size();
        string result("");
        for(int i = strSize - 1; i >= 0; i--){
            int tempRes = one * (big[i] - 48) + flag;
            result = to_string(tempRes % 10) + result;
            flag = tempRes / 10;
        }
        if(flag) result = to_string(flag) + result;
        return result;
    }

    string add(string num1, string num2){
        if(num1[0] == '0') return num2;
        if(num2[0] == '0') return num1;

        if(num1.size() < num2.size()) swap(num1, num2);
        int str1Size = num1.size(), str2Size = num2.size();
        int zeros = str1Size - str2Size;
        num2 = string(zeros, '0') + num2;

        string result("");
        int flag = 0;
        for(int i = str1Size - 1; i >= 0; i--){
            int tempRes = num1[i] - 48 + num2[i] - 48 + flag;
            result = to_string(tempRes % 10) + result;
            flag = tempRes / 10;
        }
        if(flag) result = to_string(flag) + result;
        return result;
    }
};
