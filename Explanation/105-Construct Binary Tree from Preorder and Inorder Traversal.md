# LeetCode-105-Construct Binary Tree from Preorder and Inorder Traversal-从前序与中序遍历序列构造二叉树

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/105.png)

## 综述：  
\+ 这里使用回溯法递归求解。  
\+ 设使用 p 指向前序数组，i 指向中序数组。p 指向的每一个元素都为一个节点，且前序数组的第一个元素为根节点，所以通过在中序数组中找到根节点，其左半部分为左子树，右半部分为右子树，分别递归。每次进入递归前，p++。

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
    vector<int>preOrder;
    vector<int>inOrder;
    int preOrderPos;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 && inorder.size() == 0) return NULL;

        preOrder = preorder;
        inOrder = inorder;
        preOrderPos = 0;

        TreeNode *result = DFS(0, inOrder.size() - 1);

        return result;
    }

    TreeNode* DFS(int i, int j){
        if(preOrderPos == preOrder.size()) return NULL;
        TreeNode *newNode = new TreeNode(preOrder[preOrderPos]);
        if(i < j){
            int inOrderPos;
            for(inOrderPos = i; inOrderPos <= j; inOrderPos++){
                if(inOrder[inOrderPos] == preOrder[preOrderPos]){
                    break;
                }
            }
            if (i != inOrderPos) { // 没有左子树
                ++preOrderPos;
                newNode->left = DFS(i, inOrderPos - 1);
            }
            if (j != inOrderPos) { // 没有右子树
                ++preOrderPos;
                newNode->right = DFS(inOrderPos + 1, j);
            }
        }
        return newNode;
    }
};
```


## 复杂度分析

