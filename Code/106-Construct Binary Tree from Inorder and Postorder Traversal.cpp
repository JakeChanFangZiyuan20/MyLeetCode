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