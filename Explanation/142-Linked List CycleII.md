# LeetCode-142-Linked List CycleII-环形链表II

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/142.png)





## 综述：
这题参考了题解。  
1、使用快慢指针，若有环，则两指针肯定会相遇。  
&emsp;设链表非环部分长度a，环长b，快指针走f，慢指针走s。  
&emsp;两指针相遇时：(1)f=2s; (2)f=s+nb;  
&emsp;2式nb意为快指针走了n次环后与慢指针相遇。  
&emsp;两式求解f=2nb，s=nb。  
&emsp;设k为环进口点，则k=a+nb。  
2、寻找环进口。  
&emsp;因为s已经走了nb步，再走a步即可到达环进口。  
&emsp;由于从head到环进口有a步距离，则可讲fast=head（f=0），然后快慢指针同时以步距为一个节点向前，走a步后快慢指针在环进口处相遇。  

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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;

        ListNode *slow = head, *fast = head;
        while(1){
            if(fast == NULL || fast->next == NULL) return NULL;
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                fast = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return head;
    }
};
```


## 复杂度
空间复杂度O(1)  
时间复杂度O(n)
