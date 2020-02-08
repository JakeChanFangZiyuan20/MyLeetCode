# LeetCode-641-Design Circular Deque-设计循环双端队列

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/641.png)





## 综述：  
\+ 按要求写代码。  

## Code
```
class MyCircularDeque {
private:
    int capacity, size;
    struct ListNode{
        int val;
        ListNode *last, *next;
        ListNode(int x): val(x), last(NULL), next(NULL) {}
    }*head, *rear;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        capacity = k;
        size = 0;
        head = rear = NULL;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(size == capacity) return false;
        ListNode *newNode = new ListNode(value);
        if(head == NULL){
            head = rear = newNode;
        } else{
            newNode->next = head;
            head->last = newNode;
            head = newNode;
        }
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(size == capacity) return false;
        ListNode *newNode = new ListNode(value);
        if(head == NULL){
            head = rear = newNode;
        } else{
            newNode->last = rear;
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(size == 0) return false;
        ListNode *del = head;
        if(size == 1){
            head = rear = NULL;
        } else{
            head = head->next;
            head->last = NULL;
        }
        delete del;
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(size == 0) return false;
        ListNode *del = rear;
        if(size == 1){
            head = rear = NULL;
        } else{
            rear = rear->last;
            rear->next = NULL;
        }
        delete del;
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(size == 0) return -1;
        else return head->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(size == 0) return -1;
        else return rear->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if(size == 0) return true;
        else return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if(size == capacity) return true;
        else return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
```

