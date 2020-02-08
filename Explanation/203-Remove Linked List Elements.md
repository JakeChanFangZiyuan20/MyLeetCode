# LeetCode-203-Remove Linked List Elements-移除链表元素

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/203.png)





## 综述：
使用逐个扫描方法。  

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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        ListNode *p1 = head, *p1c = head;
        while(p1 != NULL){
            if(p1->val == val){
                if(p1 == head){
                    head = head->next;
                    p1 = p1c = head;
                }else{
                    p1c->next = p1->next;
                    p1 = p1c->next;
                }
            }else{
                if(p1 != head) p1c = p1c->next;
                p1 = p1->next;
            }
        }
        return head;
    }
};
```


## 复杂度
空间复杂度O(1)  
时间复杂度O(n)
