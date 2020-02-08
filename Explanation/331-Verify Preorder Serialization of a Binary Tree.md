# LeetCode-331-Verify Preorder Serialization of a Binary Tree-验证二叉树的前序序列化

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/%E6%A0%88/img/331.png)

## 综述：  
\+ 该题目收到网络博文启发：  
\+ 从后往前遍历所给字符串：  
&emsp;&emsp;\+ 若为','，则跳过。  
&emsp;&emsp;\+ 若为'#'，则入栈。  
&emsp;&emsp;\+ 若为数字，则将连续数字字符串提取，并连续出两次栈，并压一个'#'进栈。  
&emsp;&emsp;&emsp;&emsp;\+  若连续出栈时栈为空或者只能出1次栈则返回false。  
&emsp;&emsp;\+ 遍历完成后出一次栈，若此时栈为空则返回true，否则返回false。  

## Code
```
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int num = preorder.size();
        if(num == 0) return false;
        stack<char>nullSign;
        for(int i = num - 1; i >= 0; i--){
            string curStr;
            if(preorder[i] == ',') continue;
            else if(preorder[i] == '#'){
                nullSign.push('#');
            } else {
                while(i >= 0 && preorder[i] >= '0' && preorder[i] <= '9'){
                    curStr.push_back(preorder[i--]);
                }
                i++;
                int counts = 0;
                while(!nullSign.empty() && counts != 2){
                    nullSign.pop();
                    counts += 1;
                }
                if(counts != 2) return false;
                else nullSign.push('#');
            }
            //cout << preorder[i] << ' ';
        }
        nullSign.pop();
        if(!nullSign.empty()) return false;
        return true;
    }
};
```

## 复杂度分析
时间复杂度O(n)  
空间复杂度O(n)
