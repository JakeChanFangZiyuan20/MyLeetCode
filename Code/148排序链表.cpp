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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        return sort(head, NULL);
    }

    ListNode* sort(ListNode* childhead, ListNode* end){
        if(childhead->next == end){
            childhead->next = NULL;
            return childhead;
        }
        
        ListNode *slow = childhead, *fast = childhead;
        while(fast != end && fast->next != end){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *alist = sort(childhead, slow);
        if(fast != end) fast = fast->next;
        ListNode *blist = sort(slow, fast);

        return merge(alist,blist);
    }

    ListNode* merge(ListNode* alist, ListNode *blist){
        ListNode *newlist = NULL, *newtail = NULL;
        ListNode *p1 = alist, *p2 = blist;
        while(p1 != NULL && p2 != NULL){
            if(p1->val > p2->val){
                if(newlist == NULL) newlist = newtail = p2;
                else {
                    newtail->next = p2;
                    newtail = newtail->next;
                }
                p2 = p2->next;
            } else{
                if(newtail == NULL) newlist = newtail = p1;
                else {
                    newtail->next = p1;
                    newtail = newtail->next;
                }
                p1 = p1->next;
            }
        }
        if(p1 == NULL && p2 != NULL) newtail->next = p2;
        else if(p1 != NULL && p2 == NULL) newtail->next = p1;

        return newlist;
    }
};