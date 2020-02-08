# LeetCode-144-Binary Tree Preorder Traversal-二叉树的前序遍历

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/144.png)






## 综述：  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/144-1.png)





## Code
```
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>result;
        if(root == NULL) return result;
        stack<TreeNode*>treestack;
        treestack.push(root);
        while(!treestack.empty()){
            TreeNode *curnode = treestack.top();
            treestack.pop();
            result.push_back(curnode->val);
            if(curnode->right != NULL){
                treestack.push(curnode->right);
                curnode->right = NULL;
            }
            if(curnode->left != NULL){
                treestack.push(curnode->left);
                curnode->left = NULL;
            }
        }
        return result;
    }
};
```

## 复杂度分析
空间复杂度O(n)  
时间复杂度O(n)

