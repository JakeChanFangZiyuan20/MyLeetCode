class Solution {
public:
    bool isValidSerialization(string preorder) {
        int num = preorder.size();
        if(num == 0) return false;
        stack<char>nullSign;
        for(int i = num - 1; i >= 0; i--){
            string curStr;
            if(preorder[i] == ',') continue;
            else if(preorder[i] == '#'){
                nullSign.push('#');
            } else {
                while(i >= 0 && preorder[i] >= '0' && preorder[i] <= '9'){
                    curStr.push_back(preorder[i--]);
                }
                i++;
                int counts = 0;
                while(!nullSign.empty() && counts != 2){
                    nullSign.pop();
                    counts += 1;
                }
                if(counts != 2) return false;
                else nullSign.push('#');
            }
            //cout << preorder[i] << ' ';
        }
        nullSign.pop();
        if(!nullSign.empty()) return false;
        return true;
    }
};