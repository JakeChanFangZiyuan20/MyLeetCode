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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *p1 = l1, *p2 = l2, *p3 = NULL;
        while(p1 != NULL && p2 != NULL){
            if(p2->val >= p1->val){
                if(p1->next == NULL){
                    p1->next = p2;
                    return l1;
                }
                if(p2->val <= p1->next->val){
                    p3 = p2->next;
                    p2->next = p1->next;
                    p1->next = p2;
                    p2 = p3;
                }
                else{
                    p1 = p1->next;
                }
            }
            else{
                p3 = p2->next;
                l1 = p2;
                p2->next = p1;
                p1 = p2;
                p2 = p3;
            }
        }

        return l1;
    }
};