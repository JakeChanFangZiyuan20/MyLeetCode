# LeetCode-138-Copy List with Random Pointer-复制带随机指针的链表

## 题目要求：
![avatar](https:///github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/138.png)



## 综述：
1、next拼接：按照next创建新链并连接。  
2、random拼接：逐个扫描，先提取random，然后两条链同时查找，当原链找到时，第二条链指针所指即为random值。  

## Code
```
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;

        // next 拼接
        Node *p1 = head, *newhead = new Node(p1->val), *p2 = newhead;
        while(1){
            p1 = p1->next;
            if(p1 == NULL) break;

            Node *newnode = new Node(p1->val);
            p2->next = newnode;
            p2 = p2->next;
        }

        // random 拼接
        p1 = head; p2 = newhead;
        Node *p3 = head, *p4 = newhead, *temp = NULL;
        while(p1){
            temp = p1->random;
            if(temp != NULL){
                while(p3 != temp){
                    p3 = p3->next;
                    p4 = p4->next;
                }
                p2->random = p4;
                p3 = head;
                p4 = newhead;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return newhead;
    }
};
```
  

## 复杂度
空间复杂度O(1)  
时间复杂度O(n<sup>2</sup>)
