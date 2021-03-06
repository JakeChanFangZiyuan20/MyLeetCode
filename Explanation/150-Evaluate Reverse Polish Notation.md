# LeetCode-150-Evaluate Reverse Polish Notation-逆波兰表达式求值

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/150.png)






## 综述：  
\+ 数字入栈。  
\+ 遇到计算符号将栈顶两个元素出栈并计算，将计算结果入栈。  
\+ 但tokens遍历结束时栈顶就是计算结果。  

## Code
```
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
```

## 复杂度分析
空间复杂度O(n)  
时间复杂度O(n)

