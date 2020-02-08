# LeetCode-385-Mini Parser-迷你语法分析器

## 题目要求：
![avatar](https:///github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/385.png)




## 综述：  
\+ 建立一个存储NestedInteger对象的栈。  
\+ 若所给字符串为一个数字（检测第一个字符不为'['），则直接转化（包含正负整数）。  
\+ 若所给字符串为一个列表（检测第一个字符为'['），则开始遍历：  
&emsp;&emsp;\+ 若当前字符为'['，则创建一个NestedInteger对象，并压栈。  
&emsp;&emsp;\+ 若当前字符为']'，则提取栈顶并pop，然后将刚刚提取的NestedInteger对象加入到现栈顶元素的队列中（使用NestedInteger对象的add函数）。  
&emsp;&emsp;\+ 若当前字符为数字或者'-'，则将数字部分提取，创建一个新NestedInteger对象，并将数字赋给这个新的NestedInteger对象，然后将这个NestedInteger对象加入到栈顶元素的列表中。  
&emsp;&emsp;\+ 若当前字符为','，则continue。  
\+ 遍历完后，栈顶元素即为结果。

## Code
```
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger result;
        if(s[0] == '-' || s[0] >= '0' && s[0] <= '9'){
            int number = 0;
            string::iterator iter = s.begin();
            if(s[0] == '-') iter++;
            while(iter != s.end()){
                number = number * 10 + *iter - 48;
                iter++;
            }
            if(s[0] == '-') number = -number;
            result.setInteger(number);
        } else{
            stack<NestedInteger>NIStack;
            for(string::iterator iter = s.begin(); iter != s.end(); iter++){
                if(*iter == '['){
                    NestedInteger newNI;
                    NIStack.push(newNI);
                } else if(*iter == '-' || *iter >= '0' && *iter <= '9'){
                    int number = 0, flag = 0;
                    if(*iter == '-'){
                        iter++;
                        flag = 1;
                    }
                    while(iter != s.end() && *iter >= '0' && *iter <= '9'){
                        number = number * 10 + *iter - 48;
                        iter++;
                    }
                    iter--;
                    if(flag) number = -number;
                    NestedInteger subNI(number);
                    (NIStack.top()).add(subNI);
                } else if(*iter == ']'){
                    NestedInteger topNI = NIStack.top();
                    NIStack.pop();
                    if(!NIStack.empty()){
                        (NIStack.top()).add(topNI);
                    } else{
                        result = topNI;
                    }
                }
            }
        }
        return result;
    }
};
```

## 复杂度分析
空间复杂度O(n)  
时间复杂度O(n)

