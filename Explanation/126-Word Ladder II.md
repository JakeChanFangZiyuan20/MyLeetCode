# LeetCode-126-Word Ladder II-单词接龙 II

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/126.png)

## 综述：  
\+ 本题使用 BFS 方法，如果使用 DFS （非 BFS 和 DFS 两个结合），会超时，因为多条路径走下去会在无效路径上花费大量时间。  
\+ 使用 BFS ，结合队列使用，其中队列中存的是每条路径，即一个 vector<string>，从 beginword 做为根节点，然后一层一层的更新，如果该层出现其中一个解，则将该层检查完，并将正确的路径加入到最终结果，然后从该层结束，因为下一层的所有路径长度都会比当前层大，当前层的长度已经为最短路径。对于每一层的检索，搜索过的单词不能再搜索，但新加入的单词不需要立刻进入已检索单词组，只需先记录，而在该层全部检索完后，再将标记的单词放入已检索单词组中。  
\+ 对于每一个单词，从其第一个字符开始替换为 'a' 到 'z'，然后查看是否存在字典列表中和是否在已检索单词组中，如果在字典列表和不在已检索单词组，则作为一个新单词，加入到当前列表，并将当前列表放入队列中。
\+ 对于一层一层的更新是指队列前 n 个元素长度一致，然后这 n 个元素以一个组来更新，也就是说在最外层的 while 里面还有第二个 while 来做为这一组的更新，而第二个 while 的判断标准为队列元素的长度。这一组更新完后，队列中全为下一层的元素，并且长度为刚更新完的组的长度 + 1。  
\+ 如果找到了其中一条结果路径，则设置最短长度，并继续更新该层直到结束。那么在每次进入第一个 while 时，判断当前队列中的元素长度是否为最短长度，若是则逐个抽出并检查最后一个单词是否为 endword，若是则将该路径加入结果组中，若否则 pop 并检测下一个元素，直到队列为空。  

## Code
```
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
```


## 复杂度分析

