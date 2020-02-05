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
                int curMaxHeight = 1, curMaxLength = graph[i][j];
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