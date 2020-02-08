# LeetCode-394-Decode String-字符串解码

## 题目要求：
![avatar](https:///github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/394.png)



## 综述：  
\+ 该题解法可以从逆波兰式求值中得到启发。  
\+ 遍历所给字符串：  
&emsp;&emsp;\+ 遇到左方括号立即压入字符串栈。  
&emsp;&emsp;\+ 遇到数字，若后续有数字，则将该数字字符串提取并转化成int压入到数字栈。  
&emsp;&emsp;\+ 遇到大写或小写字母，若后续有大写或小写字母，则将该字符串提取，并判断字符串栈栈顶有无非左括号字符串，若有则弹出字符串栈栈顶元素与当前字符串结合（当前字符串在后），再放入字符串栈，持续该过程直到字符串栈栈顶为左括号或为空。  
&emsp;&emsp;\+ 遇到右括则提取数字栈栈顶数字对字符串栈顶元素进行复制，然后连续弹出字符串栈栈顶元素两次，一次为复制基，一次为左括号。然后判断字符串栈栈顶有无非左括号字符串，若有则弹出字符串栈栈顶元素与当前字符串结合（当前字符串在后），再放入字符串栈，持续该过程直到字符串栈栈顶为左括号或为空。  
\+ 遍历完后，将字符串栈的元素逐一弹出按后弹出插入到前先弹出字符串前的顺序结合后，得到结果。  

## Code
```
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
```

## 复杂度分析
时间复杂度O(n)  
空间复杂度O(n)
