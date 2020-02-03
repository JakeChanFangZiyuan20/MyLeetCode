class Solution {
public:
    string decodeString(string s) {
        string result;
        if(s.size() == 0) return result;
        stack<int>NumStack;
        stack<string>StringStack;
        for(string::iterator iter = s.begin(); iter != s.end(); iter++){
            string curStr;
            if(*iter == '['){
                curStr.push_back('[');
                StringStack.push(curStr);
            } else if(*iter == ']'){
                curStr = StringStack.top();
                int num = NumStack.top();
                NumStack.pop();
                for(int i = 1; i < num; i++){
                    curStr += StringStack.top(); // 栈顶字符串重复
                }
                StringStack.pop(); // 弹出栈顶字符串
                StringStack.pop(); // 弹出左括号
                while(!StringStack.empty() && StringStack.top() != "["){
                    curStr = StringStack.top() + curStr;
                    StringStack.pop();
                }
                StringStack.push(curStr);
            } else if(*iter >= '0' && *iter <= '9'){
                while(*iter >= '0' && *iter <= '9'){ // 提取数字
                    curStr.push_back(*iter);
                    iter += 1;
                }
                iter -= 1;
                NumStack.push(stoi(curStr));
            } else if(*iter >= 'A' && *iter <= 'Z' || 
                        *iter >= 'a' && *iter <= 'z'){ // 提取字符
                while(*iter >= 'A' && *iter <= 'Z' || 
                        *iter >= 'a' && *iter <= 'z'){
                    curStr.push_back(*iter);
                    iter += 1;
                }
                iter -= 1;
                while(!StringStack.empty() && StringStack.top() != "["){
                    curStr = StringStack.top() + curStr;
                    StringStack.pop();
                }
                StringStack.push(curStr);
            }
        }
        while(!StringStack.empty()){
            result.insert(0, StringStack.top());
            StringStack.pop();
        }
        return result;
    }
};