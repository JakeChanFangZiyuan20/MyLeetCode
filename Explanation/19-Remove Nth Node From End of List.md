# LeetCode-19-Remove Nth Node From End of List-删除链表的倒数第N节点

## 题目要求：
![avatar](https:///github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/19.png)


## 综述：
1、使用快慢指针，快指针先走n步，然后两个指针一起走。<br/>
2、当快指针的next指向NULL时，则将慢指针的next指向慢指针的next的next，即删除操作。<br/>
该方法相当于一个移动窗口，因为要删除倒数第N个节点，则其到最终节点一定为N。由于删除操作最好找到删除节点的前一个节点，所以将窗口开成除去两端外中间含有N-1个节点，即在开始的时候先将快指针先走N步。<br/>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL || n == 0) return head;
        if(head->next == NULL){
            head = NULL;
            return head;
        }
        ListNode *p1 = head, *p2 = head;
        int temp = n;
        while(temp != 0){
            p2 = p2->next;
            temp -= 1;
            if(p2 == NULL){
                head = head->next;
                return head;
            }
        }
        while(p2->next != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        p1->next = p1->next->next;
        return head;
    }
};
```
  

## 其他方法
开辟记录位置空间

## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

