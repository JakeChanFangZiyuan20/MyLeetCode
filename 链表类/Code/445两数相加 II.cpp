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
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        // 提取运算数
        stack<int>left, right;
        ListNode *p1 = l1, *p2 = l2;
        while(p1 != NULL){
            left.push(p1->val);
            p1 = p1->next;
        }
        while(p2 != NULL){
            right.push(p2->val);
            p2 = p2->next;
        }
        // 计算
        stack<int>CalRes;
        int flag = 0, tempRes;
        while(!left.empty() && !right.empty()){
            tempRes = left.top() + right.top() + flag;
            CalRes.push(tempRes % 10);
            flag = tempRes / 10;
            left.pop();
            right.pop();
        }
        while(!left.empty()){
            tempRes = left.top() + flag;
            CalRes.push(tempRes % 10);
            flag = tempRes / 10;
            left.pop();
        }
        while(!right.empty()){
            tempRes = right.top() + flag;
            CalRes.push(tempRes % 10);
            flag = tempRes / 10;
            right.pop();
        }
        if(flag)CalRes.push(1);

        // 构造新链
        ListNode *newList = NULL, *p3 = NULL;
        while(!CalRes.empty()){
            ListNode *newNode = new ListNode(CalRes.top());
            CalRes.pop();
            if(newList == NULL) newList = p3 = newNode;
            else{
                p3->next = newNode;
                p3 = p3->next;
            }
        }

        return newList;
    }
};