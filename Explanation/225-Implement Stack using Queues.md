# LeetCode-225-Implement Stack using Queues-用队列实现栈

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/225.png)





## 综述：  
\+ push、top、empty操作直接调用queue的push、front、empty操作。  
\+ 对于pop操作：将queue中前n-1个元素逐个出队并放入队尾，然后将队头元素数值提取并执行queue的pop，最后返回数值。  

## Code
```
class MyStack {
private:
    queue<int>q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int num = q.size(), cur_num;
        for(int i = 1; i <= num - 1; i++){
            cur_num = q.front();
            q.pop();
            q.push(cur_num);
        }
        cur_num = q.front();
        q.pop();
        return cur_num;
    }
    
    /** Get the top element. */
    int top() {
        return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```


