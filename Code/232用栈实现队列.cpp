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