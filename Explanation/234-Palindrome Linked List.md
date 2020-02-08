# LeetCode-234-Palindrome Linked List-回文链表题解

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/234.png)





## 综述：
先用快慢指针得方法找到中间节点。<br/>
主要判断快指针节点的next和next->next：<br/>
1、先判断快指针的next是否为NULL<br/>
&emsp; 若是，则证明为奇数个节点，然后新建一个节点并使其值和慢指针所指节点的值相等，并将新建指针指向慢指针下一个节点。接着将慢指针的next指针指向NULL。<br/>
&emsp; 若否，则证明为奇数个节点，然后将快指针指向慢指针所指节点的下一个节点。接着将慢指针的next指针指向NULL。<br/>
此时head指向第一条链，快指针指向第二条链。<br/>
2、将第一条反向<br/>
3、两条链同步比较<br/>

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
```
  
## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

## 其他方法
使用快慢指针找到中间节点后，将左半部分入栈。出栈是和右半部分比较。
