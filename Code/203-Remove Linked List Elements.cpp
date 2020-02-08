class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0) return true;

        int num = s.size();
        stack<char>str_stack;
        char temp;
        for(int i = 0; i < num; i++){
            if(s[i] == ' '){
                s.erase(i-1, i);
            }
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                str_stack.push(s[i]);
            } else{
                if(str_stack.size() == 0) return false;
                temp = str_stack.top();
                if(s[i] == ')' && temp == '('){
                    str_stack.pop();
                } else if(s[i] == '}' && temp == '{'){
                    str_stack.pop();
                } else if(s[i] == ']' && temp == '['){
                    str_stack.pop();
                } else{
                    return false;
                }
            }
        }
        if(str_stack.size() != 0) return false;

        return true;
    }
};