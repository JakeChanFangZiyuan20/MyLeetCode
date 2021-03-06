# LeetCode-206-Reverse Linked List-反转链表题解

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/206.png)





## 综述：
使用三个指针，分别为p1、p2、p3。p3作用在于指引并判定是否结束。p1、p2作用在于将两个节点间的指向反转。

## 以下是过程解释：
以一个四节点链表为例：<br/>
1、p3会一直在p1所在节点的前一个结点。<br/>
2、当p1移动到p2所在节点的前一个结点时，会将p1所在节点的指针指向p2，然后将p3赋值给p1，p3向前移动。<br/>
3、由于p3会在p1所在节点的前一个结点，向前移动一个节点是会先判断该节点是否为NULL，如果是则证明p1在原链表最后一个节点，此时直接将first（还指向原来的第一个节点，此first指向的节点的指针还指向原来链表的第二个节点）的指针指向NULL，然后将p1赋值给first，即让first指向原链表最后一个节点。然后结束。
### 1 初始状态
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/206-1.png)




### 2 p3和p1向前移动，将p1所指节点指向p2
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/206-2.png)




### 3 步骤同上
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/206-3.png)




### 4 步骤同上
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/206-4.png)




### 5 p3检测到所直接点位NULL，将first所指节点指向NULL后将p1赋值给first，完成反转
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/206-5.png)




  
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode *p1 = head, *p2 = head, *p3 = head->next;
        while(1){
            if(p3 == NULL)
                break;
            else{

                p1 = p3;
                p3 = p3->next;
            }
            p1->next = p2;
            p2 = p1;
        }
        head->next = NULL;
        head = p1;
        return head;
    }
};
```

## 由Draymonder提供的代码修改，很简练
```
ListNode * reverse(ListNode* head) {
    if (head == NULL) return head;
    ListNode *pre = NULL, *cur =  head;
    while (cur) {
        ListNode *next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
```
  
## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

## 其他方法
使用一个栈，每读取一个节点进一次栈，然后全部读完后逐个出栈并连接
