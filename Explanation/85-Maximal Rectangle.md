# LeetCode-85-Maximal Rectangle-最大矩形

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/85.png)





## 综述：  
\+ 方法一：  
\+ 该方法效率较低。  
\+ m--矩阵行数，n--矩阵列数。  
\+ 遍历每一个节点，对于该位置(i, j)若为1，则入栈。  
\+ 每次取栈顶元素，计算从该点开始向右走，直到为0或者出界，计数curl，找到宽为1，长为curl的矩阵。  
\+ 然后将curl和在栈中除栈顶位置外，其他位置能够如上一句描述的所获得的所有curl中的最短比较，若小于则更新最短，并用最短乘当前栈中元素个数获取当前面积，然后和最大面积比较。  
\+ 若(i+1, j)也为1，则入栈。  
  
\+ 方法二：参考  
\+ 从每一个1点为其能形成的矩形的右下节点出发。  
\+ 对于matrix的每一行，对每一个1点进行计数，并放入到对应的int的二维数组graph：  
&emsp;&emsp;\+ 若当前为0，对应为0；若当前为1，则查看其前一个是否为0，为0，则对应1，不为0，则对应前一个数+1。  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/85-1.png)




\+ 构建完二维数组后，遍历每一个元素：  
&emsp;&emsp;\+ 若当前为0，则continue；  
&emsp;&emsp;\+ 若不为0，则设当前最大高curMaxHeight为1，最大宽curMaxHeight为graph[i][j]，当前最大面积curNodeS为curMaxHeight * curMaxLength。然后在同一列，以当前节点开始向上遍历，向上1格，curMaxHeight + 1，然后判断向上后的位置里的数值和curMaxLength比较，若小于，则用向上后的位置里的数值更新curMaxLength。然后设newS为curMaxLength * curMaxHeight，再和curNodeS比较大小，若大于curNodeS，则用newS更新curNodeS。若向上操作完成后，用curNodeS和maxS比较大小，大于则用curNodeS更新maxS。  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/85-2.png)





## Code-1
```
// 第一次完成代码
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        // m--矩阵行数，n--矩阵列数
        int maxS = 0, m = matrix.size(), n = (*matrix.begin()).size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == '0' || (m - i) * (n - j) <= maxS){
                    // 对于 (m - i) * (n - j) <= maxS
                    // 若当前点在该矩形中所能构成的最大子矩形面积小于已有maxS，则跳过
                    continue;
                }

                pair<int , int>curNode(i, j);
                stack<pair<int , int>>NodeStack;
                NodeStack.push(curNode);
                int minl = n + 1; // minl 为长
                int rowS = 0;
                while(true){
                    int topfirst = (NodeStack.top()).first;
                    int curl = 1;
                    for(int k = j + 1; k < n; k++){
                        if(matrix[topfirst][k] == '1'){
                            curl++;
                        }
                        else break;
                    }
                    if(curl < minl) minl = curl;
                    if(rowS == 0){
                        rowS = curl;
                    }
                    int rowcolS = minl * NodeStack.size(), curS; // NodeStack.size()宽度
                    (rowcolS > rowS) ? curS = rowcolS : curS = rowS; 
                    if(curS > maxS) maxS = curS;

                    if(topfirst < m - 1 && 
                    matrix[topfirst + 1][j] != '0'){
                        pair<int, int>nextNode(topfirst + 1, j);
                        NodeStack.push(nextNode);
                    } else{
                        break;
                    }
                }
            }
        }
        return maxS;
    }
};
```

## Code-2
```
//第二次完成代码
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int maxS = 0;
        vector<vector<int>>graph;
        for(int i = 0; i < matrix.size(); i++){
            vector<int>newList;
            newList.push_back(matrix[i][0] - 48);
            for(int j = 1; j < matrix[i].size(); j++){
                int pushnum;
                if(matrix[i][j] != '0'){
                    if(matrix[i][j - 1] != '0'){
                        pushnum = *(newList.end() - 1) + 1;
                    }
                    else{
                        pushnum = 1;
                    }
                } else{
                    pushnum = 0;
                }
                newList.push_back(pushnum);
            }
            graph.push_back(newList);
        }
        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph[i].size(); j++){
                if(graph[i][j] == 0){
                    continue;
                }
                int curMaxHeight = 1, curMaxHeight = graph[i][j];
                int curNodeS = curMaxHeight * curMaxLength;
                for(int k = i - 1; k >= 0; k--){
                    curMaxHeight++;
                    if(graph[k][j] < curMaxLength){
                        curMaxLength = graph[k][j];
                    }
                    int newS = curMaxLength * curMaxHeight;
                    if(newS > curNodeS) curNodeS = newS;
                }
                if(curNodeS > maxS) maxS = curNodeS;
            }
        }
        return maxS;
    }
};
```

## 复杂度分析
\+ 方法一：  
&emsp;&emsp;\+ m--矩阵行数，n--矩阵列数  
&emsp;&emsp;\+ 时间复杂度O(m<sup>2</sup>n<sup>2</sup>)  
&emsp;&emsp;\+ 空间复杂度O(n)  
  
\+ 方法二：  
&emsp;&emsp;\+ m--矩阵行数，n--矩阵列数  
&emsp;&emsp;\+ 时间复杂度O(m<sup>2</sup>n)  
&emsp;&emsp;\+ 空间复杂度O(mn)  
