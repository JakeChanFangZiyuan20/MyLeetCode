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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        ListNode *p1 = head;
        int num = 0;
        while(1){
            num += 1;
            if(p1->next == NULL) {
                p1->next = head;
                break;
            }
            p1 = p1->next;
        }
        int step = num - k % num;
        while(step != 0){
            head = head->next;
            step -= 1;
        }
        p1 = head;
        while(p1 != NULL){
            if(p1->next == head){
                p1->next = NULL;
            }
            p1 = p1->next;
        }

        return head;
    }
};