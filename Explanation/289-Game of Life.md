# LeetCode-289-Game of Life-生命游戏

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/289.png)

## 综述：  
\+ 方法一：  
\+ 先设定下一个状态的两个记录表（vector<pair<int, int>>）：nextLive 和 nextDead。  
\+ 遍历每一个位置，然后统计该位置周围八个格的活细胞个数，根据题目说明，来判断当前是进入 nextLive 还是 nextDead。  
\+ 然后根据两个记录表对于 nextLive 则在 borad 中填 1， nextDeaad 则在 board 中填 0。  

\+ 方法二：
\+ 在方法一的基础上不适用两个记录表，在所给二维数组上进行标记。  
\+ 需要进行两次遍历，第一次进行标记，第二次进行修改。  
\+ 标记：对于每一个位置，都需要计数其周围的活细胞数，但这里只需周围八个格元素大于 0，则计数器 +1。计数完毕，若当前为 0，则将计数器结果取负后赋值给当前位置。若当前位置为 1，则当 count > 0 时直接将 count 赋值给当前位置。标记完后的二维数组每一个元素大于 0，表示活细胞，小于等于 0，表示死细胞。该元素取绝对值为该元素周围活细胞数。  
\+ 修改：遍历标记后的二维数组，若当前数值大于 0，则为活细胞，按照活细胞的规则将该位置进行修改。若当前数值小于等于 0，则为死细胞，按照死细胞的规则将该位置进行修改。

## Code
```
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
```

## Code-2
```
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
```

## 复杂度分析
方法一：  
空间复杂度O(mn)  
时间复杂度O(mn)  

方法二：  
空间复杂度O(1)  
时间复杂度O(mn)  

