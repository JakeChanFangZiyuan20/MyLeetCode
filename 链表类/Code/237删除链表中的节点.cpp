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
    void deleteNode(ListNode* node) {
        while(1){
            if(node->next->next == NULL){
                node->val = node->next->val;
                node->next = NULL;
                break;
            }
            node->val = node->next->val;
            node = node->next;
        }
    }
};