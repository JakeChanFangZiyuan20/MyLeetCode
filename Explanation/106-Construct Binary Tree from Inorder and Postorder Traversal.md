# LeetCode-106-Construct Binary Tree from Inorder and Postorder Traversal-从中序与后序遍历序列构造二叉树

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/106.png)

## 综述：  
\+ 该题做法跟[LeetCode105.从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)做法大致相同，但区别在于后序数组从后往前遍历并且先进入右子树则递归再进入左子树的递归。  

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
private:
    vector<int>inOrder;
    vector<int>postOrder;
    int postOrderPos;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 && postorder.size() == 0) return NULL;

        inOrder = inorder;
        postOrder = postorder;
        postOrderPos = postOrder.size() - 1;

        TreeNode *result = DFS(0, inOrder.size() - 1);

        return result;
    }
    TreeNode* DFS(int i, int j){
        if(postOrderPos == -1) return NULL;
        TreeNode *newNode = new TreeNode(postOrder[postOrderPos]);
        if(i < j){
            int inOrderPos;
            for(inOrderPos = i; inOrderPos <= j; inOrderPos++){
                if(inOrder[inOrderPos] == postOrder[postOrderPos]){
                    break;
                }
            }
            if (j != inOrderPos) { // 没有右子树
                --postOrderPos;
                newNode->right = DFS(inOrderPos + 1, j);
            }
            if (i != inOrderPos) { // 没有左子树
                --postOrderPos;
                newNode->left = DFS(i, inOrderPos - 1);
            }
        }
        return newNode;
    }
};
```


## 复杂度分析

