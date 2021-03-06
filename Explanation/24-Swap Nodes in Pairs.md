# LeetCode-24-Swap Nodes in Pairs-两两交换链表中的节点

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/24.png)





## 综述：
1、这里一共使用额外三个指针p1，p2，p3。  
2、p1一直指向交换节点对中的左节点，p2一直指向交换节点对中的右节点。  
3、p3的作用为在交换非第1、2结点时，例如正在交换第N和N+1节点，p3位于第N-1节点，用于指向p2。  
交换后，需要交换的是第N+2和N+3节点，此时p1指向的N节点位于N+2的左方，所以先将p1值赋给p3，然后p1 = p1.next（p1指向第N+2节点），p2 = p1.next。  

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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *p1 = head, *p2 = head->next, *p3 = NULL;
        head = head->next;
        while(1){
            // 交换
            p1->next = p2->next;
            p2->next = p1;
            if(p3 != NULL) p3->next = p2;
            // 移动
            p3 = p1;
            p1 = p1->next;
            if(p1 == NULL || p1->next == NULL) break;
            p2 = p1->next;
        }
        
        return head;
    }
};
```
  


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

