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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *p1 = head, *p2 = head->next, *p3 = NULL;
        while(p2 != NULL){
            if(p1->val != p2->val){
                p3 = p1;
                p1 = p1->next;
                p2 = p2->next;
            }
            else{
                while(p2 != NULL && p1->val == p2->val){
                    p2 = p2->next;
                }
                if(p3 != NULL)p3->next = p2;
                else head = p2;
                if(p2 != NULL){
                    p1 = p2;
                    p2 = p2->next;
                }
            }
        }
        return head;
    }
};