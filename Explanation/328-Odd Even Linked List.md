# LeetCode-328-Odd Even Linked List-奇偶链表

## 题目要求：
![avatar](https:///github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/328.png)



## 综述：
逐个扫描，奇数位进入奇数链，偶数位进入偶数链，最后奇偶链合并。  

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        // 奇数链
        ListNode *oddlist = NULL, *op = NULL;
        // 偶熟链
        ListNode *evenlist = NULL, *ep = NULL; 
        int flag = 1; // 奇偶标志，0为偶，1为奇
        while(head != NULL){
            if(flag == 1){
                if(oddlist == NULL){
                    oddlist = op = head;
                    head = head->next;
                }
                else{
                    op->next = head;
                    head = head->next;
                    op = op->next;
                }
                op->next = NULL;
                flag = 0;
            }else if(flag == 0){
                if(evenlist == NULL){
                    evenlist = ep = head;
                    head = head->next;
                }
                else{
                    ep->next = head;
                    head = head->next;
                    ep = ep->next;
                }
                ep->next = NULL;
                flag = 1;
            }
        }
        // 合并
        op->next = evenlist;
        return oddlist;
    }
};
```


## 复杂度
空间复杂度O(1)  
时间复杂度O(n)
