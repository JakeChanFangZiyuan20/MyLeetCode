# LeetCode-237-Delete Node in a Linked List-删除链表中的节点

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/237.png)





## 综述：
此题目给定节点node即为要删除的节点。<br/>
使用后一个节点值向当前节点值覆盖的方式。<br/>
所需判定为当前节点的next的next是否为NULL，即当前节点是否为原链表中倒数第二个节点：<br/>
&emsp; 若是，则将下一个节点覆盖当前节点，然后将当前节点的next指向NULL。  

## 注意：
该题目给定的四个条件很重要：<br/>
1、链表至少包含两个节点。<br/>
2、链表中所有节点的值都是唯一的。<br/>
3、给定的节点为非末尾节点并且一定是链表中的一个有效节点。<br/>
4、不要从你的函数中返回任何结果。<br/>

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
    void deleteNode(ListNode* node) {
        while(1){
            if(node->next->next == NULL){
                node->val = node->next->val;
                node->next = NULL;
                break;
            }
            node->val = node->next->val;
            node = node->next;
        }
    }
};
```
  
## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

