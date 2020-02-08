# LeetCode-224-Basic Calculator-基本计算器

## 题目要求：
![avatar](https:///github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/224.png)



## 综述：  
第一步：将所给字符串转化成逆波兰表达式。  
&emsp;&emsp;1）建立vector\<string>tokens存储逆波兰表达式运算数和运算符。  
&emsp;&emsp;2）遍历遇到空字符跳过。  
&emsp;&emsp;3）遍历遇到左括号直接进符号栈。  
&emsp;&emsp;4）遍历遇到右括号将符号栈栈顶符号压入tokens，并弹出，持续直到遇到栈顶为左括号，则将左括号弹出，并不进入符号栈。  
&emsp;&emsp;5）遍历遇到加号或减号将符号栈栈顶符号压入tokens，并弹出，持续直到遇到栈顶为左括号或者符号栈为空，将此时的加号或减号压入符号栈。  
&emsp;&emsp;6）遍历遇到数字，若后续也为数字，则提取出该数字字符串并压入tokens。  
&emsp;&emsp;7）遍历完所给字符串后，若符号栈不为空，则逐一将符号栈栈顶元素压入tokens。  
第二步：计算逆波兰表达式--LeetCode150

## Code
```
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
```

## 复杂度分析
时间复杂度O(n)
空间复杂度O(n)