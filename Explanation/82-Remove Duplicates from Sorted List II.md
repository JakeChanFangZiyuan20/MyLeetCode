# LeetCode-82-Remove Duplicates from Sorted List II-删除排序链表中的重复元素II

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/82.png)





## 综述：
这里使用三个指针p1，p2，p3。  
p1作为前置指针，p2作为移动指针，判断p2值是否等于p1值。  
p3指针的作用作为定位head位置和一连串连续数字前的位置。  

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *p1 = head, *p2 = head->next, *p3 = NULL;
        while(p2 != NULL){
            if(p1->val != p2->val){
                p3 = p1;
                p1 = p1->next;
                p2 = p2->next;
            }
            else{
                while(p2 != NULL && p1->val == p2->val){
                    p2 = p2->next;
                }
                if(p3 != NULL)p3->next = p2;
                else head = p2;
                if(p2 != NULL){
                    p1 = p2;
                    p2 = p2->next;
                }
            }
        }
        return head;
    }
};
```
  


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

