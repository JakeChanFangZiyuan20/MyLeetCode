class Solution {
private:
    vector<vector<char>>board;
    string word;
    int m, n;
    bool result;
    vector<vector<int>>mark;
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;

        // m 行，n 列
        m = board.size(), n = board[0].size();
        if(m * n < word.size()) return false;

        this->board = board;
        this->word = word;
        result = false;
        mark = vector<vector<int>>(m, vector<int>(n, 0));

        for(int i = 0; i <m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    mark[i][j] = 1;
                    DFS(i, j, 1);
                    mark[i][j] = 0;
                    if(result == true) break;
                }
            }
            if(result == true) break;
        }

        return result;
    }

    void DFS(int i, int j, int nextCharPos){
        if(result == true) return ;
        if(nextCharPos == word.size()){
            result = true;
            return ;
        }

        if(j + 1 < n && mark[i][j + 1] == 0 
                && board[i][j + 1] == word[nextCharPos]){ // to right
            mark[i][j + 1] = 1;
            DFS(i, j + 1, nextCharPos + 1);
            mark[i][j + 1] = 0;
        }
        if(i + 1 < m && mark[i + 1][j] == 0 
                && board[i + 1][j] == word[nextCharPos]){ // to down
            mark[i + 1][j] = 1;
            DFS(i + 1, j, nextCharPos + 1);
            mark[i + 1][j] = 0;
        }
        if(j - 1 >= 0 && mark[i][j - 1] == 0
                && board[i][j - 1] == word[nextCharPos]){ // to left
            mark[i][j - 1] = 1;
            DFS(i, j - 1, nextCharPos + 1);
            mark[i][j - 1] = 0;
        }
        if(i - 1 >= 0 && mark[i - 1][j] == 0 
                && board[i - 1][j] == word[nextCharPos]){ // to up
            mark[i - 1][j] = 1;
            DFS(i - 1, j, nextCharPos + 1);
            mark[i - 1][j] = 0;
        }

    }
};