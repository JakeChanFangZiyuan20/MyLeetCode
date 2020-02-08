# LeetCode-141-Linked List Cycle-环形链表

## 题目要求：
![avatar](https:///github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/141.png)


## 综述：
设置一个指针sp，扫描原链，扫一个让其next指向sp，如果扫描指针指向NULL，则返回false，如果扫描指针指向sp，则返回true。  

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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)return false;

        ListNode *p1 = head, *p2 = NULL, *sp = new ListNode(16);
        while(1){
            if(p1 == NULL) return false;
            if(p1 == sp) return true;
            p2 = p1->next;
            p1->next = sp;
            p1 = p2;
        }
        
        return true;
    }
};
```


## 复杂度
空间复杂度O(1)  
时间复杂度O(n)
