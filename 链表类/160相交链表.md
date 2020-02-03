# LeetCode-160-Intersection of Two Linked Lists-相交链表

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/%E9%93%BE%E8%A1%A8%E7%B1%BB/img/160.png)

## 综述：
该题参考题解。  
为了找到相交节点，需要找到两指针（分别指向两链）与相交节点同距离的情况。该情况会出现在短链表的首节点。  
由于重合处节点数相同，只需将长链表指针先走一定步数（长度差），使得长链表节点指针距离相交节点步数同短链表头节点到相交节点步数相同，然后长短链表指针再同时走，即可找到相交点。  


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB ==NULL) return NULL;

        ListNode *pa = headA, *pb = headB;
        int numa = 0, numb =0, step = 0, count = 0;
        while(pa != NULL){
            numa += 1;
            pa = pa->next;
        }
        while(pb != NULL){
            numb += 1;
            pb = pb->next;
        }
        step = numa - numb;
        if(step < 0) step = -step;

        pa = headA, pb = headB;
        if(numa > numb){
            while(count != step){
                pa = pa->next;
                count += 1;
            }
        } else if(numa < numb){
            while(count != step){
                pb = pb->next;
                count += 1;
            }
        }

        while(pa != NULL && pb != NULL){
            if(pa == pb)return pa;
            else{
                pa = pa->next;
                pb = pb->next;
            }
        }

        return NULL;
    }
};
```


## 复杂度
空间复杂度O(1)  
时间复杂度O(n)
