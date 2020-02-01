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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root == NULL) return result;
        stack<TreeNode*>treestack;
        treestack.push(root);
        int nextflag = 2;
        while(!treestack.empty()){
            vector<int>newline;
            vector<TreeNode*>nodeline;
            while(!treestack.empty()){
                TreeNode *temp = treestack.top();
                treestack.pop();
                nodeline.push_back(temp);
                newline.push_back(temp->val);
            }

            result.push_back(newline);

            int num = nodeline.size();
            if(nextflag == 2){ // 当前为奇数层
                for(int i = 0; i < num; i++){
                    if(nodeline[i]->left != NULL)
                        treestack.push(nodeline[i]->left);
                    if(nodeline[i]->right != NULL)
                        treestack.push(nodeline[i]->right);
                }
                nextflag = 1;
            } else{ // 当前为偶数层
                for(int i = 0; i < num; i++){
                    if(nodeline[i]->right != NULL)
                        treestack.push(nodeline[i]->right);
                    if(nodeline[i]->left != NULL)
                        treestack.push(nodeline[i]->left);
                }
                nextflag = 2;
            }
        }

        return result;
    }
};