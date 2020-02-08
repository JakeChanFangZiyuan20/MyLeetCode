# LeetCode-109-Convert Sorted List to Binary Search Tree-有序链表转换二叉搜索树

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/109.png)





## 综述：
使用递归：  
1、找到中点，作为树的父节点。  
2、左半部分找中点作为左子树父节点。  
3、右半部分找中点作为右子树父节点。  

寻找中点：  
使用快慢指针。  

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode *treehead = NULL;
        if(head == NULL) return treehead;
        if(head->next == NULL){
            treehead = new TreeNode(head->val);
            return treehead;
        }

        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        treehead = new TreeNode(slow->val);
        treehead->left = childTree(head, slow);
        if(slow->next != NULL)treehead->right = childTree(slow->next, NULL);

        return treehead;
    }

    TreeNode* childTree(ListNode* head, ListNode* end){
        TreeNode *treehead = NULL;
        if(head == NULL) return treehead;
        if(head->next == end){
            treehead = new TreeNode(head->val);
            return treehead;
        }

        ListNode *slow = head, *fast = head;
        while(fast != end && fast->next != end){
            slow = slow->next;
            fast = fast->next->next;
        }

        treehead = new TreeNode(slow->val);
        treehead->left = childTree(head, slow);
        if(slow->next != end){
            if(fast == end){
                treehead->right = childTree(slow->next, fast);
            }
            else if(fast->next == end){
                treehead->right = childTree(slow->next, fast->next);
            }
        }

        return treehead;
    }
};
```
  


