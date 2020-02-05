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