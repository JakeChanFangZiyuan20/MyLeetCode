/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*>treestack;
public:
    BSTIterator(TreeNode* root) {
        TreeNode *ptr = root;
        while(ptr != NULL){
            treestack.push(ptr);
            ptr = ptr->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *curNode = treestack.top();
        treestack.pop();
        if(curNode->right != NULL) {
            TreeNode *ptr = curNode->right;
            while(ptr != NULL){
                treestack.push(ptr);
                ptr = ptr->left;
            }
        }
        return curNode->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(treestack.empty()) return false;
        else return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */