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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || n == 0) return head;
        if(head->next == NULL){
            head = NULL;
            return head;
        }
        ListNode *p1 = head, *p2 = head;
        int temp = n;
        while(temp != 0){
            p2 = p2->next;
            temp -= 1;
            if(p2 == NULL){
                head = head->next;
                return head;
            }
        }
        while(p2->next != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return head;
    }
};