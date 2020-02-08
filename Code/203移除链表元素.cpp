/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        ListNode *p1 = head, *p1c = head;
        while(p1 != NULL){
            if(p1->val == val){
                if(p1 == head){
                    head = head->next;
                    p1 = p1c = head;
                }else{
                    p1c->next = p1->next;
                    p1 = p1c->next;
                }
            }else{
                if(p1 != head) p1c = p1c->next;
                p1 = p1->next;
            }
        }
        return head;
    }
};