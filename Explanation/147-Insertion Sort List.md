# LeetCode-147-Insertion Sort List-对链表进行插入排序

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/147.png)





## 综述：
以节点单位进行脱离及插入。  

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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode *p1 = head, *p1_cur = head, *p2 = head->next, *p2_cur = head, *p3 = NULL;
        while(p2 != NULL){
            while(p1 != p2 && p2 != NULL){
                if(p1->val > p2->val){
                    p2_cur->next = p2->next;
                    p2->next = p1;
                    if(p1 == head){
                        head = p2;
                    } else{
                        p1_cur->next = p2;
                    }
                    p2 = p2_cur->next;
                    p1 = p1_cur = head;
                } else{
                    if(p1 != head) p1_cur = p1_cur->next;
                    p1 = p1->next;
                }
            }
            if(p2 != NULL){
                p2 = p2->next;
                p2_cur = p2_cur->next;
                p1 = p1_cur = head;
            }
        }
        return head;
    }
};
```


## 复杂度
空间复杂度O(1)  
时间复杂度O(n<sup>2</sup>)
