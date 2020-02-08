# LeetCode-94-Binary Tree Inorder Traversal-二叉树的中序遍历

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/94.png)





## 综述：  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/92-1.png)





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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        if(root == NULL) return result;
        TreeNode *p1 = root, *p2 = root->left;
        stack<TreeNode*>treestack;
        treestack.push(root);
        while(!treestack.empty()){
            p1 = treestack.top();
            if(p1->left != NULL){
                treestack.push(p1->left);
                p1->left = NULL;
            } else{
                result.push_back(p1->val);
                treestack.pop();
                if(p1->right != NULL){
                    treestack.push(p1->right);
                }
            }
        }
        
        return result;
    }

};
```

## 复杂度分析
空间复杂度O(n)  
时间复杂度O(n)

