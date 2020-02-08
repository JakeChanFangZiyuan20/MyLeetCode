# LeetCode-23-Merge k Sorted Lists-合并K个有序链表

## 题目要求：
![avatar](https:///github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/23.png)



## 综述：
以vector中的第一条非空链表为基础，后续链表逐个元素比较插入。

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;

        ListNode *head = NULL, *newhead = NULL;
        ListNode *p1 = NULL, *p1c = NULL, *p2 = NULL, *p2c = NULL;
        int list_num = lists.size();
        for(int i = 0; i < list_num; i++){
            if(lists[i] == NULL) continue;
            if(head == NULL){
                head = lists[i];
            } else{
                newhead = lists[i];
                p1 = p1c = head;
                p2 = newhead;
                while(newhead != NULL){
                    if(p1 == NULL){
                        p1c->next = newhead;
                        break;
                    }
                    if(p2->val <= p1->val){
                        newhead = newhead->next;
                        if(p1 == head){
                            p2->next = p1;
                            head = p2;
                            p1 = p1c = head;
                        } else{
                            p2->next = p1;
                            p1c->next = p2;
                            p1c = p1c->next;
                        }
                        p2 = newhead;
                    } else{
                        if(p1 != head) p1c = p1c->next;
                        p1 = p1->next; 
                    }
                }
            }
        }

        return head;
    }
};
```
  


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(kn)

