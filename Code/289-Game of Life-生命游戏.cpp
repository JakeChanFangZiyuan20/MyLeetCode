// 方法一
class Solution {
private:
    int dir1[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dir2[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size(), cols= board[0].size();
 
        vector<pair<int, int>>nextLive, nextDead;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                // count cells that are around the board[i][j]
                int count = 0;
                for(int k = 0; k < 8; k++){
                    int x = dir1[k] + i, y = dir2[k] + j;
                    if(0 <= x && x < rows 
                            && 0 <= y && y < cols 
                                && board[x][y] == 1){
                        count++;
                    }
                }
                //cout << i << ' ' << j << ' ' << count << endl;
                if(board[i][j] == 0){ // current dead
                    if(count == 3){
                        nextLive.push_back(pair<int, int>(i, j));
                    } else{
                        nextDead.push_back(pair<int, int>(i, j));
                    }
                } else{ // current live
                    if(count == 2 || count == 3){
                        nextLive.push_back(pair<int, int>(i, j));
                    } else{
                        nextDead.push_back(pair<int, int>(i, j));
                    }
                }
            }
        }

        int lives = nextLive.size(), deads = nextDead.size();
        //cout << "Live:" << endl;
        for(int i = 0; i < lives; i++){
            //cout << nextLive[i].first << ' ' << nextLive[i].second << endl;
            board[nextLive[i].first][nextLive[i].second] = 1;
        }
        //cout << "Dead:" << endl;
        for(int i = 0; i < deads; i++){
            //cout << nextDead[i].first << ' ' << nextDead[i].second << endl;
            board[nextDead[i].first][nextDead[i].second] = 0;
        }
    }
};

// 方法二
class Solution {
private:
    int dir1[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dir2[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size(), cols= board[0].size();
 
        //vector<pair<int, int>>nextLive, nextDead;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){

                int count = 0;
                for(int k = 0; k < 8; k++){
                    int x = dir1[k] + i, y = dir2[k] + j;
                    if(0 <= x && x < rows 
                            && 0 <= y && y < cols 
                                && board[x][y] > 0){
                        count++;
                    }
                }

                if(board[i][j] == 0){ // current dead
                    board[i][j] = -count;
                } else{ // current live
                    if(count > 0)board[i][j] = count;
                }

            }
        }

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){

                int count = abs(board[i][j]);
                if(board[i][j] > 0){
                    if(count == 2 || count == 3) board[i][j] = 1;
                    else board[i][j] = 0;
                } else{
                    if(count == 3) board[i][j] = 1;
                    else board[i][j] = 0;
                }

            }
        }
    }
};