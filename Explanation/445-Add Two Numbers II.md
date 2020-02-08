# LeetCode-445-Add Two Numbers II-两数相加 II

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/%E9%93%BE%E8%A1%A8%E7%B1%BB/img/445.png)

## 综述：
\+ 将两条链分别进栈1，2。  
\+ 两栈同时出栈相加计算，结果放于第三个栈。  
\+ 第三个栈逐个出栈并建立节点。  
  
\+ 第三个栈可以不需要。

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
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        // 提取运算数
        stack<int>left, right;
        ListNode *p1 = l1, *p2 = l2;
        while(p1 != NULL){
            left.push(p1->val);
            p1 = p1->next;
        }
        while(p2 != NULL){
            right.push(p2->val);
            p2 = p2->next;
        }
        // 计算
        stack<int>CalRes;
        int flag = 0, tempRes;
        while(!left.empty() && !right.empty()){
            tempRes = left.top() + right.top() + flag;
            CalRes.push(tempRes % 10);
            flag = tempRes / 10;
            left.pop();
            right.pop();
        }
        while(!left.empty()){
            tempRes = left.top() + flag;
            CalRes.push(tempRes % 10);
            flag = tempRes / 10;
            left.pop();
        }
        while(!right.empty()){
            tempRes = right.top() + flag;
            CalRes.push(tempRes % 10);
            flag = tempRes / 10;
            right.pop();
        }
        if(flag)CalRes.push(1);

        // 构造新链
        ListNode *newList = NULL, *p3 = NULL;
        while(!CalRes.empty()){
            ListNode *newNode = new ListNode(CalRes.top());
            CalRes.pop();
            if(newList == NULL) newList = p3 = newNode;
            else{
                p3->next = newNode;
                p3 = p3->next;
            }
        }

        return newList;
    }
};
```


## 复杂度
空间复杂度O(m + n)  
时间复杂度O(m + n)
