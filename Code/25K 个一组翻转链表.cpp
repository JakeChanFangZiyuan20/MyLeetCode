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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0 ||k == 1) return head;

        int count = 0;
        ListNode *newhead = NULL, *newtail = NULL, *repos = NULL;
        ListNode *relist = NULL, *retail = NULL, *p1 = NULL, *p2 = NULL, *p3 = NULL;
        ListNode *pos = NULL;

        while(head != NULL){
            while(count != k && head != NULL){
                if(relist == NULL) relist = retail = head;
                else {
                    retail->next = head;
                    retail = retail->next;
                }
                head = head->next;
                count += 1;
            }
            if(count == k){
                retail->next = NULL;
                p1 = relist, p2 = relist->next, p3 = p2->next;
                while(true){
                    p2->next = p1;
                    p1 = p2;
                    p2 = p3;
                    if(p3 != NULL) p3 = p3->next;
                    else{
                        relist->next = NULL;
                        repos = relist;
                        relist = p1;
                        break;
                    }
                }
                if(newhead == NULL) newhead = newtail = relist;
                else newtail->next = relist;
                newtail = repos;
            } else{
                if(newhead == NULL) return relist;
                newtail->next = relist;
            }
            count = 0;
            relist = retail = NULL;
        }

        return newhead;
    }
};