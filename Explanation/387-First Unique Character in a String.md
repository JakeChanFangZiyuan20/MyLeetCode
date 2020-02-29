# LeetCode-387-First Unique Character in a String-字符串中的第一个唯一字符

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/387.png)

## 综述：  
\+ 可使用 unordered_map<char, vector\<int>> 来记录出现过的字母及其位置集合。  
\+ 遍历 unordered_map ，如果该字母位置集合只有一位，则将这一位和结果位置比较，取小者，并更新结果位置。  

## Code
```
class Solution {
public:
    int firstUniqChar(string s) {
        int len = s.size();
        if(len == 0) return -1;
        if(len == 1) return 0;

        unordered_map<char, vector<int>>sMap;
        for(int i = 0; i < len; i++){
            auto iter = sMap.find(s[i]);
            if(iter == sMap.end()){
                sMap.insert({s[i], vector<int>(1, i)});
            } else{
                (iter->second).push_back(i);
            }
        }

        int prePos = -1;
        for(auto iter = sMap.begin(); iter != sMap.end(); iter++){
            if((iter->second).size() == 1){
                if(prePos == -1) prePos = (iter->second)[0];
                else prePos = min(prePos, (iter->second)[0]);
            }
        }

        return prePos;
    }
};
```


## 复杂度分析
空间复杂度O(n)  
时间复杂度O(n)

