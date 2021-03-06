# LeetCode-232-Implement Queue using Stacks-用栈实现队列

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/232.png)





## 综述：  
\+ push、empty操作直接调用stack的push、empty操作。  
\+ 对于pop操作：将原栈中后n-1个元素逐个出栈并放入辅助栈，然后将原栈头元素数值提取并执行原栈的pop，最后返回数值。  
\+ 对于peek，会在push时判断栈是否为空，若空则赋值给headnum；会在pop时，将原栈中后n-1个元素逐个出栈并放入辅助栈后，将辅助栈栈顶赋值给headnum

## Code
```
class MyQueue {
    stack<int>s;
    int headnum;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(s.empty()) headnum = x;
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = headnum;
        stack<int>assist;
        int temp;
        while(!s.empty()){
            temp = s.top(); s.pop();
            if(!s.empty()) assist.push(temp);
        }
        if(!assist.empty())headnum = assist.top();
        while(!assist.empty()){
            s.push(assist.top());
            assist.pop();
        }
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        return headnum;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```


