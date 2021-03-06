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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode *p1 = head, *p1_cur = head, *p2 = head->next, *p2_cur = head, *p3 = NULL;
        while(p2 != NULL){
            while(p1 != p2 && p2 != NULL){
                if(p1->val > p2->val){
                    p2_cur->next = p2->next;
                    p2->next = p1;
                    if(p1 == head){
                        head = p2;
                    } else{
                        p1_cur->next = p2;
                    }
                    p2 = p2_cur->next;
                    p1 = p1_cur = head;
                } else{
                    if(p1 != head) p1_cur = p1_cur->next;
                    p1 = p1->next;
                }
            }
            if(p2 != NULL){
                p2 = p2->next;
                p2_cur = p2_cur->next;
                p1 = p1_cur = head;
            }
        }
        return head;
    }
};