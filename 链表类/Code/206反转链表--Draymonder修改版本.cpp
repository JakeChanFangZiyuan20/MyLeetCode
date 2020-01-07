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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode *p1 = head, *p2 = head, *p3 = head->next;
        while(1){
            if(p3 == NULL)
                break;
            else{

                p1 = p3;
                p3 = p3->next;
            }
            p1->next = p2;
            p2 = p1;
        }
        head->next = NULL;
        head = p1;
        return head;
    }
};