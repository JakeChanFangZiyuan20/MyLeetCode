# LeetCode-92-Reverse Linked List-反转链表II

## 题目要求：
![avatar](https:///github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/92.png)



## 综述：
这题核心反转，把反转链提取后进行反转，然后再拼接上。  

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head->next == NULL) return head;
        if(m - n == 0) return head;

        // 添加一个头节点
        ListNode *NewNode = new ListNode(0);
        NewNode->next = head;
        head = NewNode;
        
        // first、last指针位于反转链的两端
        ListNode *first = head, *last = head;
        // head2指向反转链头，p1、p2、p3用于反转
        ListNode *head2 = NULL, *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL;
        // 计算first、last移动步数
        int step1 = m - 1, step2 = n;
        // 移动first
        while(step1){
            first = first->next;
            step1 -= 1;
        }
        // 指向反转链
        head2 = p1 = first->next;
        // 移动last
        while(step2){
            last = last->next;
            step2 -= 1;
        }
        // 使反转链最后节点指向NULL
        p4 = last->next;
        last->next = NULL;
        last = p4;
        // 反转
        p2 = head2->next;
        p3 = p2->next;
        while(1){
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            if(p3 == NULL) break;
            else p3 = p3->next;    
        }
        head2->next = NULL;
        p4 = head2; // p4此时指向反转链末
        head2 = p1;
        // 连接反转链
        first->next = head2;
        p4->next = last;
        // head回到原链头
        head = head->next;

        return head;
    }
};
```
  

## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

