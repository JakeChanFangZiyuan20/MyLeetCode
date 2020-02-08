# LeetCode-20-Valid Parentheses-有效的括号

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/20.png)






## 综述：  
1、遇到左括号进栈。  
2、遇到右括号，先判断栈是否为空再提取栈顶括号是否匹配，若栈空返回false。  
3、遇到空字符删除。  
4、一次遍历完字符串后，判断栈是否为空，若空返回true，若不为空返回false。  

## Code
```
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
```

## 复杂度分析
空间复杂度O(n)  
时间复杂度O(n)

