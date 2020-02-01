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