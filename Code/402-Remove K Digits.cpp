class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k)return "0";
        int count = 0;
        string::iterator pre;
        for(string::iterator iter = num.begin() + 1; iter != num.end(); iter++){
            pre = iter - 1;
            while(iter != num.begin() && *pre > *iter){
                num.erase(pre);
                iter -= 1;
                pre = iter - 1;
                count++;
                //cout << *iter << endl;
                if(count == k) break;
            }
            if(count == k) break;
        }
        if(count != k){
            for(int i = k - count; i > 0; i--){
                num.erase(num.end() - 1);
            }
        }
        while(num.size() > 1 && *num.begin() == '0'){
            num.erase(num.begin());
        }
        return num;
    }
};