# LeetCode-86-Partition List-分割链表

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/86.png)





## 综述：  
这里使用原链逐个扫描同x值作比较的方式，比x大的节点脱离放大链，比x小的节点脱离放小链，最后拼接。  

## 注意：
1、x值比链中节点都大。  
2、x值比链中节点都小。  

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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        // l1为小链，l2为大链
        ListNode *l1 = NULL, *l2 = NULL;
        // p1扫描原链，p2指向小链的末节点，p3指向大链的末节点
        ListNode *p1 = head,*p2 = NULL, *p3 = NULL;
        while(p1 != NULL){
            if(p1->val < x){
                if(l1 == NULL){
                    l1 = p2 = p1;
                    p1 = p1->next;
                }
                else{
                    p2->next = p1;
                    p1 = p1->next;
                    p2 = p2->next;
                }
                p2->next = NULL;
            }
            else{
                if(l2 == NULL){
                    l2 = p3 = p1;
                    p1 = p1->next;
                }
                else{
                    p3->next = p1;
                    p1 = p1->next;
                    p3 = p3->next;
                }
                p3->next = NULL;
            }
        }
        
        // 两个极端情况
        if(l1 == NULL) return l2; // k比原链任何一个数都大
        if(l2 == NULL) return l1; // k比原链任何一个数都小

        // 拼接
        p2->next = l2;

        return l1;
    }
};
```
  

## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

