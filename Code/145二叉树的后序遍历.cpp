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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>result;
        if(root == NULL) return result;
        stack<TreeNode*>treestack;
        treestack.push(root);
        while(!treestack.empty()){
            TreeNode *curnode = treestack.top();
            if(curnode->left == NULL && curnode->right == NULL){
                result.push_back(curnode->val);
                treestack.pop();
            } else{
                if(curnode->right != NULL){
                    treestack.push(curnode->right);
                    curnode->right = NULL;
                }
                if(curnode->left != NULL){
                    treestack.push(curnode->left);
                    curnode->left = NULL;
                } 
            }
        }

        return result;
    }
};