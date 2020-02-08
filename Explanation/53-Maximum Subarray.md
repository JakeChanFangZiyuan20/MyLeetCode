# LeetCode-53-Maximum Subarray-最大子序和

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/2.png)





## 综述：  
1、本题采取两个链表同步相加，即抽出两个链表当前值相加后判断进位，将个位赋值覆盖两个链表当前值。<br/>
2、如果同步结束，即两个链表同结点数，若有进位则在第一个链表最后加上一个值为1的节点。<br/>
3、如果链1比链2长则将在链1改为所指节点值加0，并加进位，然后修改当前值，如此重复到最后一个节点，如果有进位则添加一个值为1的节点在最后。最后返回链1<br/>
4、如果链2比链1长则同第3条。<br/>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int a, b, c, d = 0;
        ListNode *p1 = l1, *p2 = l2, *result = NULL, *pre, *NewNode = new ListNode(0);
        while(p1 != NULL && p2 != NULL){
            a = p1->val;
            b = p2->val;
            c = a + b + d;
            d = c / 10;
            p1->val = p2->val = c % 10;
            
            if(p1->next == NULL && p2->next == NULL){
                if(d){
                    NewNode->val = d;
                    p1->next = NewNode;
                }
                result = l1;
                break;
            }
            else if(p1->next != NULL && p2->next == NULL){
                pre = p1;
                p1 = p1->next;
                while(p1 != NULL){
                    a = p1->val;
                    c = a + d;
                    d = c / 10;
                    p1->val = c % 10;
                    p1 = p1->next;
                    pre = pre->next;
                }
                if(d){
                    NewNode->val = d;
                    pre->next = NewNode;
                }
                result = l1;
                break;
            }
            else if(p1->next == NULL && p2->next != NULL){
                pre = p2;
                p2 = p2->next;
                while(p2 != NULL){
                    b = p2->val;
                    c = b + d;
                    d = c / 10;
                    p2->val = c % 10;
                    p2 = p2->next;
                    pre = pre->next;
                }
                if(d){
                    NewNode->val = d;
                    pre->next = NewNode;
                }
                result = l2;
                break;
            }

            p1 = p1->next;
            p2 = p2->next;
        }

        return result;
    }
};
```

## 需要修改的地方：
代码过于繁杂

## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

