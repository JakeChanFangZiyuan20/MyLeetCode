class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() == 1 && a[0] == '0') return b;
        if(b.size() == 1 && b[0] == '0') return a;

        if(a.size() < b.size()) swap(a, b);
        int zeros = a.size() - b.size();
        b = string(zeros, '0') + b;

        string result("");
        int flag = 0, temp;
        for(int i = a.size() - 1; i >= 0 ; i--){
            temp = a[i] - 48 + b[i]  - 48 + flag;
            result = to_string(temp % 2) + result;
            flag = temp / 2;
        }

        if(flag) result = "1" + result;
        
        return result;
    }
};