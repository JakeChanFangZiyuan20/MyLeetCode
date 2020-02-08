# LeetCode-25-Reverse Nodes in k-Group-K 个一组翻转链表

## 题目要求：
![avatar](https:///github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/25.png)



## 综述：
扫描出k个节点作为新链进行翻转后拼接到最终结果链的尾部。  
若扫描出节点数小于k则直接拼接。  

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0 ||k == 1) return head;

        int count = 0;
        ListNode *newhead = NULL, *newtail = NULL, *repos = NULL;
        ListNode *relist = NULL, *retail = NULL, *p1 = NULL, *p2 = NULL, *p3 = NULL;
        ListNode *pos = NULL;

        while(head != NULL){
            while(count != k && head != NULL){
                if(relist == NULL) relist = retail = head;
                else {
                    retail->next = head;
                    retail = retail->next;
                }
                head = head->next;
                count += 1;
            }
            if(count == k){
                retail->next = NULL;
                p1 = relist, p2 = relist->next, p3 = p2->next;
                while(true){
                    p2->next = p1;
                    p1 = p2;
                    p2 = p3;
                    if(p3 != NULL) p3 = p3->next;
                    else{
                        relist->next = NULL;
                        repos = relist;
                        relist = p1;
                        break;
                    }
                }
                if(newhead == NULL) newhead = newtail = relist;
                else newtail->next = relist;
                newtail = repos;
            } else{
                if(newhead == NULL) return relist;
                newtail->next = relist;
            }
            count = 0;
            relist = retail = NULL;
        }

        return newhead;
    }
};
```
  


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(nk)

