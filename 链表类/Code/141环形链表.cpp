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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)return false;

        ListNode *p1 = head, *p2 = NULL, *sp = new ListNode(16);
        while(1){
            if(p1 == NULL) return false;
            if(p1 == sp) return true;
            p2 = p1->next;
            p1->next = sp;
            p1 = p2;
        }
        
        return true;
    }
};