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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB ==NULL) return NULL;

        ListNode *pa = headA, *pb = headB;
        int numa = 0, numb =0, step = 0, count = 0;
        while(pa != NULL){
            numa += 1;
            pa = pa->next;
        }
        while(pb != NULL){
            numb += 1;
            pb = pb->next;
        }
        step = numa - numb;
        if(step < 0) step = -step;

        pa = headA, pb = headB;
        if(numa > numb){
            while(count != step){
                pa = pa->next;
                count += 1;
            }
        } else if(numa < numb){
            while(count != step){
                pb = pb->next;
                count += 1;
            }
        }

        while(pa != NULL && pb != NULL){
            if(pa == pb)return pa;
            else{
                pa = pa->next;
                pb = pb->next;
            }
        }

        return NULL;
    }
};