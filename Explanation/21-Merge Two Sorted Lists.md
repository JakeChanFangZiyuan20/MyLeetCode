# LeetCode-21-Merge Two Sorted Lists-合并两个有序链表

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/21.png)





## 综述：
这里选择最后返回链1，所以将链2的节点插入链1。  
两个指针p1，p2分别指向链1，链2。  
若此时p2所指节点val大于等于p1所指节点val，则将p1向前移动，若判断p1的next值大于p2所指节点值，则将p2所指节点插入到p1所指节点后，并将p1指向新插入节点。  
若小于，则将p2所指节点插入到p1所指节点前，并将p1指向新插入节点。  

## Code
```
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        ListNode *p1 = l1, *p2 = l2, *p3 = NULL;
        while(p1 != NULL && p2 != NULL){
            if(p2->val >= p1->val){
                if(p1->next == NULL){
                    p1->next = p2;
                    return l1;
                }
                if(p2->val <= p1->next->val){
                    p3 = p2->next;
                    p2->next = p1->next;
                    p1->next = p2;
                    p2 = p3;
                }
                else{
                    p1 = p1->next;
                }
            }
            else{
                p3 = p2->next;
                l1 = p2;
                p2->next = p1;
                p1 = p2;
                p2 = p3;
            }
        }

        return l1;
    }
};
```
  


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

