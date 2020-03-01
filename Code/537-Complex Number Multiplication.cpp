class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int str1Len = a.size(), str2Len = b.size();
        
        string a1, a2, b1, b2, c1, c2;

        for(int i = 0; i < str1Len; i++){
            if(a[i] == '+'){
                a1 = a.substr(0, i);
                a2 = a.substr(i + 1, str1Len);
                break;
            }
        }

        for(int i = 0; i < str2Len; i++){
            if(b[i] == '+'){
                b1 = b.substr(0, i);
                b2 = b.substr(i + 1, str2Len);
                break;
            }
        }

        c1 = to_string(stoi(a1) * stoi(b1) - stoi(a2) * stoi(b2));
        c2 = to_string(stoi(a2) * stoi(b1) + stoi(a1) * stoi(b2));

        return c1 + "+" + c2 + "i";
    }
};