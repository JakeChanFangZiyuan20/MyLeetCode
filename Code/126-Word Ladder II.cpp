class Solution {
private:
    vector<vector<string>>result;
    unordered_set<string>strSet;
    unordered_set<string>strVisitedSet;
    queue<vector<string>>strListQue;
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        if(n == 0) return result;

        for(int i = 0; i < n; i++){
            strSet.insert(wordList[i]);
        }

        if(strSet.count(endWord) == 0) return result;

        strListQue.push(vector<string>(1, beginWord));
        strVisitedSet.insert(beginWord);
        int shortestSize = -1;

        while(!strListQue.empty()){
            if(shortestSize != -1){
                if(*((strListQue.front()).end() - 1) == endWord){
                    result.push_back(strListQue.front());
                }
                strListQue.pop();
                continue;
            }

            unordered_set<string>curVisitedSet;
            int curSize = (strListQue.front()).size();
            while((strListQue.front()).size() == curSize){
                vector<string>curStrList = strListQue.front();
                strListQue.pop();

                string lastWord = *(curStrList.end() - 1), originStr = lastWord;
                int lastWordSize = lastWord.size();
                for(int i = 0; i < lastWordSize; i++){
                    lastWord = originStr;
                    for(char character = 'a'; character <= 'z'; character++){
                        lastWord[i] = character;

                        if(strSet.count(lastWord) && strVisitedSet.count(lastWord) == 0){
                            vector<string>newStrList(curStrList);
                            newStrList.push_back(lastWord);
                            strListQue.push(newStrList);

                            curVisitedSet.insert(lastWord);

                            if(shortestSize == -1 && lastWord == endWord) {
                                shortestSize = newStrList.size();
                            }
                        }
                    }
                }

            }

            for(auto iter = curVisitedSet.begin(); iter != curVisitedSet.end(); iter++){
                strVisitedSet.insert(*iter);
            }

        }

        return result;
    }
};