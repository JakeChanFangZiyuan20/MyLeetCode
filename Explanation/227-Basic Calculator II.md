# LeetCode-227-Basic Calculator II-基本计算器 II

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/227.png)

## 综述：  
\+ 数据栈和符号栈结合加减乘除优先级。  

## Code
```
class Solution {
private:
    stack<int>numbers;
    stack<char>operaters;
public:
    int calculate(string s) {
        int strLength = s.size();
        if (strLength == 0) return 0;

        string number;
        int a, b;
        char operater;
        for (int i = 0; i < strLength; i++) {
            if (s[i] == ' ') continue;
            if ('0' <= s[i] && s[i] <= '9') {
                number = "";
                while (i < strLength && '0' <= s[i] && s[i] <= '9') {
                    number.push_back(s[i]);
                    i++;
                }
                i--;

                if (!operaters.empty() && 
                        (operaters.top() == '*' || operaters.top() == '/')) {
                    b = stoi(number);
                    a = numbers.top(); numbers.pop();
                    operater = operaters.top(); operaters.pop();

                    if (operater == '*') numbers.push(a * b);
                    else numbers.push(a / b);
                } else {
                    numbers.push(stoi(number));
                } 

            } else {
                if (!operaters.empty() &&
                        (operaters.top() == '+' || operaters.top() == '-') &&
                            (s[i] != '*' && s[i] != '/')) {
                    b = numbers.top(); numbers.pop();
                    a = numbers.top(); numbers.pop();
                    operater = operaters.top(); operaters.pop();

                    if (operater == '+') numbers.push(a + b);
                    else numbers.push(a - b);
                }
                operaters.push(s[i]);
            }
        }

        while (!operaters.empty()) {
            b = numbers.top(); numbers.pop();
            a = numbers.top(); numbers.pop();

            operater = operaters.top(); operaters.pop();
            if (operater == '+') numbers.push(a + b);
            else numbers.push(a - b);
        }

        return numbers.top();
    }
};

```


## 复杂度分析
空间复杂度O(n)  
时间复杂度O(n)

