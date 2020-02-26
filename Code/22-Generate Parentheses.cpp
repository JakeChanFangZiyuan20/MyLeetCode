class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0) return vector<string>(1, "");
        if(n == 1) return vector<string>(1, "()");

        vector<string>result;
        queue<pair<string, pair<int , int>>>groupQue;
        groupQue.push(pair("(", pair(1, 0)));
        while(!groupQue.empty()){
            int curSize = ((groupQue.front()).first).size();
            if(curSize == n * 2){
                result.push_back((groupQue.front()).first);
                groupQue.pop();
                continue;
            }
            while(curSize == ((groupQue.front()).first).size()){
                pair<string, pair<int , int>>curOne = groupQue.front();
                groupQue.pop();

                if((curOne.second).first < n){
                    pair<string, pair<int , int>>newOne(curOne);
                    newOne.first += "(";
                    (newOne.second).first += 1;
                    groupQue.push(newOne);
                }

                if((curOne.second).first > (curOne.second).second && 
                        (curOne.second).second < n){
                    pair<string, pair<int , int>>newOne(curOne);
                    newOne.first += ")";
                    (newOne.second).second += 1;
                    groupQue.push(newOne);
                }
            }
        }
        return result;
    }
};