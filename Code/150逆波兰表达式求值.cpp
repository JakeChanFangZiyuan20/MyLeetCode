#include<string>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>tokenstack;
        int num = tokens.size();
        for(int i = 0; i < num; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || 
                tokens[i] == "*" || tokens[i] == "/"){
                int b = tokenstack.top(); 
                tokenstack.pop();
                int a = tokenstack.top();
                tokenstack.pop();
                if(tokens[i] == "+"){
                    tokenstack.push(a + b);
                } else if(tokens[i] == "-"){
                    tokenstack.push(a - b);
                } else if(tokens[i] == "*"){
                    tokenstack.push(a * b);                    
                } else if(tokens[i] == "/"){
                    tokenstack.push(a / b);                    
                }
            } else{
                tokenstack.push(stoi(tokens[i]));
            }
        }
        return tokenstack.top();
    }
};