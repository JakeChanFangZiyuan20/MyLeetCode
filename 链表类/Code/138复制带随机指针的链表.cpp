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