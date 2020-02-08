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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        // 奇数链
        ListNode *oddlist = NULL, *op = NULL;
        // 偶熟链
        ListNode *evenlist = NULL, *ep = NULL; 
        int flag = 1; // 奇偶标志，0为偶，1为奇
        while(head != NULL){
            if(flag == 1){
                if(oddlist == NULL){
                    oddlist = op = head;
                    head = head->next;
                }
                else{
                    op->next = head;
                    head = head->next;
                    op = op->next;
                }
                op->next = NULL;
                flag = 0;
            }else if(flag == 0){
                if(evenlist == NULL){
                    evenlist = ep = head;
                    head = head->next;
                }
                else{
                    ep->next = head;
                    head = head->next;
                    ep = ep->next;
                }
                ep->next = NULL;
                flag = 1;
            }
        }
        // 合并
        op->next = evenlist;
        return oddlist;
    }
};