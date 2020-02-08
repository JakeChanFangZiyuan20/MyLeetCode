# LeetCode-103-Binary Tree Zigzag Level Order Traversal-二叉树的锯齿形层次遍历

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/103.png)






## 综述：  
\+ 设二叉树首层为奇数层，则奇数层从左到右，偶数层从右到左。  
\+ 设nextflag为标志下一层奇偶性，1为奇，2为偶。  
\+ 保证栈内一组数（vector\<int>）全出栈后可立即加入到结果vector<vector\<int>>中。  
·按照当前层的结果顺序遍历：  
&emsp;++ 若当前为奇数层，则当前层和原来层顺序一样并对下一层入栈时遍历该层节点，每节点按左子树先进右子树后进入栈。  
&emsp;++ 若当前为偶数层，则当前层和原来层顺序相反并对下一层入栈时遍历该层节点，每节点按右子树先进左子树后进入栈。  

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
```

## 复杂度分析
空间复杂度O(n)  
时间复杂度O(n)

