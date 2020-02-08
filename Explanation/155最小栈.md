# LeetCode-155-Min Stack-最小栈

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/%E6%A0%88/img/155.png)

## 综述：  
\+ 一开始直接刚，使用链表建栈，不适用系统stack，然后在getmin中使用逐个搜寻的暴力方式，最终时长100+ms。  
\+ 参考：使用系统stack，并建立两个栈，一个数据栈，一个为辅助栈。  
\+ &emsp;数据栈正常入栈。  
\+ &emsp;辅助栈在空时必须入栈，随后如果是小等于栈顶数值则入栈，出栈时若数据栈top等于辅助栈top则辅助栈也一同出栈。

## Code
```
class MinStack {
private:
    stack<int>s1;
    stack<int>s2;
public:
    /** initialize your data structure here. */
    MinStack() {;
    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty() || x <= s2.top())
            s2.push(x);
    }
    
    void pop() {
        if(s1.top() == s2.top())
            s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

## 复杂度分析
空间复杂度O(n)  
时间复杂度O(1)

