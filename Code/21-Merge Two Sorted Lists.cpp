class Solution {
public:
    int calculate(string s) {
        vector<string>tokens; // 逆波兰表达式
        stack<char>operatorstack; // 运算符及括号栈

        // 转化至逆波兰表达式
        for(string::iterator iter = s.begin(); iter != s.end(); iter++){
            if(*iter == ' ') continue;
            else{ // 非空字符
                if(*iter >= '0' && *iter <= '9'){ // 数字串
                    string number;
                    while(*iter >= '0' && *iter <= '9'){
                        number.push_back(*iter);
                        iter += 1;
                        if(iter == s.end()) break;
                    }
                    iter -= 1;
                    tokens.push_back(number);
                } else{ // 运算符或括号
                    if(*iter == '(') operatorstack.push('(');
                    else if(*iter == ')'){
                        while(operatorstack.top() != '('){
                            string cur_operator;
                            cur_operator.push_back(operatorstack.top());
                            operatorstack.pop();
                            tokens.push_back(cur_operator);
                        }
                        operatorstack.pop(); // 弹出'('
                    } else if(*iter == '+' || *iter == '-'){
                        if(operatorstack.empty()){
                            operatorstack.push(*iter);
                        } else{
                            while(operatorstack.top() == '+' || 
                                operatorstack.top() == '-'){
                                string cur_operator;
                                cur_operator.push_back(operatorstack.top());
                                operatorstack.pop();
                                tokens.push_back(cur_operator);
                                if(operatorstack.empty()) break;
                            }
                            operatorstack.push(*iter);
                        }
                    }
                }

            }

        }
        if(!operatorstack.empty()){ 
            while(!operatorstack.empty()){
                string cur_operator;
                cur_operator.push_back(operatorstack.top());
                operatorstack.pop();
                tokens.push_back(cur_operator);
            }
        }

        /*
        for(vector<string>::iterator iter = tokens.begin(); iter != tokens.end(); iter++){
            cout << *iter << ' ';
        }
        cout << endl;
        */

        // 计算逆波兰表达式
        stack<int>numberstack;
        for(vector<string>::iterator iter = tokens.begin(); iter != tokens.end(); iter++){
            if(*iter != "+" && *iter != "-"){
                numberstack.push(stoi(*iter));
            } else{
                int b = numberstack.top(); numberstack.pop();
                int a = 0; 
                if(!numberstack.empty()){
                    a = numberstack.top(); 
                    numberstack.pop();
                }
                if(*iter == "+"){
                    numberstack.push(a + b);
                } else if(*iter == "-"){
                    numberstack.push(a - b);
                }
            }
        }

        return numberstack.top();
    }
};