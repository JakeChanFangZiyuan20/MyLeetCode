# LeetCode-173-Binary Search Tree Iterator-二叉搜索树迭代器

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/173.png)





## 综述：  
\+ 该题一开始的想法是中序遍历整个树，数值存储在容器内，那么next和hasnext的函数处理就容易了。  
\+ 但看到空间复杂度需要O(h)，h为树的高度，如果按照上述则会使O(n)，n为节点个数，明显不符。  
\+ 最后参考了讨论里的内容：  
\+ &emsp;&emsp;使用一个栈，先中序遍历到最小值，每读取一个节点则该节点入栈。  
\+ &emsp;&emsp;next函数中，先提取top，然后pop，对于刚刚top的节点判断其右子树是否存在，若存在则将右子树入栈并中序遍历找到最小值，每读取一个节点则该节点入栈。  
\+ &emsp;&emsp;hasnext函数中若栈为空返回false，否则返回true。  

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
class BSTIterator {
private:
    stack<TreeNode*>treestack;
public:
    BSTIterator(TreeNode* root) {
        TreeNode *ptr = root; // 先中序遍历到最小值
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
```

## 复杂度分析
空间复杂度O(n)，n为树高

