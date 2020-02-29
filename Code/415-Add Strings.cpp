class Solution {
public:
    string addStrings(string num1, string num2) {
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