# LeetCode-22-Generate Parentheses-括号生成

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/22.png)

## 综述：  
\+ 本题采用宽度优先搜索。  
\+ 下图是 n = 3 的图示：  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/22-1.png)
\+ 可以看出层数等于该层合格的字符串的长度。合格的字符串只该字符串中，左括号数目小于等于 n，右括号数目小于等于左括号数目。  
\+ 从第 i 层到第 i + 1 层。对于第 i 层的某一个字符串，其子字符串只可能有两种情况，一种是在尾部加入左括号，另一种是在尾部加入右括号。先考察是否可以加入左括号，判断条件为当前左括号数目小于 n 。再考察是否可以加入右括号，判断当前左括号数是否大于右括号，并还需要满足右括号数小于 n 。  

## Code
```
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
```


## 复杂度分析

