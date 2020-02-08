# LeetCode-341-Flatten Nested List Iterator-扁平化嵌套列表迭代器

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/341.png)





## 综述：  
\+ 使用一个队列做为结果存储。  
\+ 先将所给vector逐一倒序插入栈，然后检查栈顶：  
&emsp;&emsp;\+ 若栈顶为isInteger，则将其数值提取插入到队列。  
&emsp;&emsp;\+ 若栈顶不为isInteger，则将其内部各元素倒序插入栈中。重新检查栈顶。  
\+ 对于next函数则返回队列首部并pop。  
\+ 对于hasNext函数则检查队列是否为空。
 

## Code
```
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    queue<int>result;
    stack<NestedInteger>NIStack;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i = nestedList.size() - 1; i >= 0; i--){
            NIStack.push(nestedList[i]);
        }
        while(!NIStack.empty()){
            NestedInteger curItem = NIStack.top();
            NIStack.pop();
            if(curItem.isInteger()){
                result.push(curItem.getInteger());
            } else{
                vector<NestedInteger>list;
                list = curItem.getList();
                for(int i = list.size() - 1; i >= 0; i--){
                    NIStack.push(list[i]);
                }
            }
        }
    }

    int next() {
        int nextNum = result.front();
        result.pop();
        return nextNum;
    }

    bool hasNext() {
        return !result.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
```

## 复杂度分析
时间复杂度O(n)  
空间复杂度O(n)
