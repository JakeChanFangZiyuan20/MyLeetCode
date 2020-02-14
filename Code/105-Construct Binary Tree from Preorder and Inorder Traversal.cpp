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