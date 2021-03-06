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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;
        ListNode *slow = head, *fast = head;

        // 寻找中点，将原链分成两部分
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newhead = slow->next; // 原链后半部分
        slow->next = NULL;

        // 反转后半部分链
        if(newhead != NULL && newhead->next != NULL){
            ListNode *p1 = newhead, *p2 = newhead->next, *p3 = NULL;
            while(1){
                p3 = p2->next;
                p2->next = p1;
                p1 = p2;
                p2 = p3;
                if(p2 == NULL){
                    newhead->next = NULL;
                    newhead = p1;
                    break;
                }
            } 
        }

        // 后半部分链错位拼接到前半部分链
        ListNode *ptr = head,*ptr2 = NULL, *isrt = NULL;
        while(ptr != NULL && newhead != NULL){
            isrt = newhead;
            newhead = newhead->next;
            isrt->next = ptr->next;
            ptr2 = ptr->next;
            ptr->next = isrt;
            ptr = ptr2;
        }
    }
};