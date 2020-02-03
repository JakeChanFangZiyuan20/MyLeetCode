# LeetCode-61-Rotate List-旋转链表

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/%E9%93%BE%E8%A1%A8%E7%B1%BB/img/61.png)

## 综述：
先处理：  
扫描一遍链表获得节点总数num并将最后节点next指向head成环。  
计算新链表head位置：  
设step为head从原链表头节点向前移动步数，step = num - num % k  
最后处理：  
使用一个新指针找到新head位置的前一个节点，使其next指向NULL，最终返回head。

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0) return head;
        ListNode *p1 = head;
        int num = 0;
        while(1){
            num += 1;
            if(p1->next == NULL) {
                p1->next = head;
                break;
            }
            p1 = p1->next;
        }
        int step = num - k % num;
        while(step != 0){
            head = head->next;
            step -= 1;
        }
        p1 = head;
        while(p1 != NULL){
            if(p1->next == head){
                p1->next = NULL;
            }
            p1 = p1->next;
        }

        return head;
    }
};
```
  


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

