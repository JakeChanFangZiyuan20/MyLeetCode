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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode *p1 = head, *p2 = head, *p3 = NULL, *head2 = new ListNode(0);
        // 快慢指针查找中点
        while(1){
            if(p2->next == NULL){
                head2->val = p1->val;
                head2->next = p1->next;
                break;
            }
            if(p2->next->next == NULL){
                head2 = p1->next;
                break;
            }
            p1 = p1->next;
            p2 = p2->next->next;
        }
        p1->next = NULL;

        // 反转前半段列表
        p1 = p2 = head; p3 = head->next;
        while(1){
            if(p3 == NULL) break;
            else{
                p1 = p3;
                p3 = p3->next;
            }
            p1->next = p2;
            p2 = p1;
        }
        head->next = NULL;
        head = p1;

        // 比对
        p1 = head, p2 = head2;
        while(p1){
            if(p1->val != p2->val)
                return false;
            else{
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        return true;
    }
};