# LeetCode-83-Remove Duplicates from Sorted List-删除排序链表中的重复元素

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/83.png)





## 综述：
这里使用两个指针p1，p2，p3。  
p1作为前置指针，p2作为移动指针，判断p2值是否等于p1值，等于则p2向前，待不等时则p1->next指向p2，并p1和p2向前。  
若一直不等时，p1和p2向前。  

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *p1 = head, *p2 = head->next;
        while(p2 != NULL){
            if(p1->val == p2->val){
                p2 = p2->next;
                if(p2 == NULL){
                    p1->next = NULL;
                    break;
                }
            }
            else{
                p1->next = p2;
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return head;
    }
};
```
  


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

