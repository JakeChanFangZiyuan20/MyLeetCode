class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>result;
        if(matrix.size() == 0) return result;

        int m = matrix.size(), n = matrix[0].size();
        map<pair<int, int>, int>pointsMap;
        queue<pair<int, int>>pointsQue;
        pointsQue.push(pair<int, int>(0, 0));
        string direction = "right";
        while(!pointsQue.empty()){
            pair<int, int>curPoint = pointsQue.front();
            pointsQue.pop();
            result.push_back(matrix[curPoint.first][curPoint.second]);
            pointsMap[curPoint] = 0;
            
            int i = curPoint.first, j = curPoint.second;
            //cout << i << ',' << j << endl;
            if(direction == "right") {
                if(j + 1 < n && 
                        pointsMap.find(pair<int, int>(i, j + 1)) == pointsMap.end()){
                    pointsQue.push(pair<int, int>(i, j + 1));
                } else if( i + 1 < m &&
                        pointsMap.find(pair<int, int>(i + 1, j)) == pointsMap.end()){
                    pointsQue.push(pair<int, int>(i + 1, j));
                    direction = "down";
                }
                continue; 
            }
            if(direction == "down") {
                if(i + 1 < m && 
                        pointsMap.find(pair<int, int>(i + 1, j)) == pointsMap.end()){
                    pointsQue.push(pair<int, int>(i + 1, j));
                } else if( j - 1 >= 0 &&
                        pointsMap.find(pair<int, int>(i, j - 1)) == pointsMap.end()){
                    pointsQue.push(pair<int, int>(i, j - 1));
                    direction = "left";
                }
                continue;
            }
            if(direction == "left") {
                if(j - 1 >= 0 && 
                        pointsMap.find(pair<int, int>(i, j - 1)) == pointsMap.end()){
                    pointsQue.push(pair<int, int>(i, j - 1));
                } else if( i - 1 >= 0 &&
                        pointsMap.find(pair<int, int>(i - 1, j)) == pointsMap.end()){
                    pointsQue.push(pair<int, int>(i - 1, j));
                    direction = "up";
                }
                continue;
            }
            if(direction == "up") {
                if(i - 1 >= 0 && 
                        pointsMap.find(pair<int, int>(i - 1, j)) == pointsMap.end()){
                    pointsQue.push(pair<int, int>(i - 1, j));
                } else if( j + 1 < n &&
                        pointsMap.find(pair<int, int>(i, j + 1)) == pointsMap.end()){
                    pointsQue.push(pair<int, int>(i, j + 1));
                    direction = "right";
                }
                continue;
            }
        }

        return result;
    }
};