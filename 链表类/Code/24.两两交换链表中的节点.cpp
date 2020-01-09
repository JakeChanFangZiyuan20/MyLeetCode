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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *p1 = head, *p2 = head->next, *p3 = NULL;
        head = head->next;
        while(1){
            // 交换
            p1->next = p2->next;
            p2->next = p1;
            if(p3 != NULL) p3->next = p2;
            // 移动
            p3 = p1;
            p1 = p1->next;
            if(p1 == NULL || p1->next == NULL) break;
            p2 = p1->next;
        }
        
        return head;
    }
};