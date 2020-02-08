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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a, b, c, d = 0;
        ListNode *p1 = l1, *p2 = l2, *result = NULL, *pre, *NewNode = new ListNode(0);
        while(p1 != NULL && p2 != NULL){
            a = p1->val;
            b = p2->val;
            c = a + b + d;
            d = c / 10;
            p1->val = p2->val = c % 10;
            
            if(p1->next == NULL && p2->next == NULL){
                if(d){
                    NewNode->val = d;
                    p1->next = NewNode;
                }
                result = l1;
                break;
            }
            else if(p1->next != NULL && p2->next == NULL){
                pre = p1;
                p1 = p1->next;
                while(p1 != NULL){
                    a = p1->val;
                    c = a + d;
                    d = c / 10;
                    p1->val = c % 10;
                    p1 = p1->next;
                    pre = pre->next;
                }
                if(d){
                    NewNode->val = d;
                    pre->next = NewNode;
                }
                result = l1;
                break;
            }
            else if(p1->next == NULL && p2->next != NULL){
                pre = p2;
                p2 = p2->next;
                while(p2 != NULL){
                    b = p2->val;
                    c = b + d;
                    d = c / 10;
                    p2->val = c % 10;
                    p2 = p2->next;
                    pre = pre->next;
                }
                if(d){
                    NewNode->val = d;
                    pre->next = NewNode;
                }
                result = l2;
                break;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        return result;
    }
};