# LeetCode-49-Group Anagrams-字母异位词分组

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/49.png)

## 综述：  
\+ 首先要理解字母异位词的意思。  
\+ 对于每一组字母异位词，这一组中的任一字符串的字典序都是相同的，所以任取一个为代表是可以的。  
\+ 所以先设置 unordered_map<string, vector<string>> ，然后从左向右遍历每一个字符串，检测到每个字符串时如果其字典序的字符串在 map 中，则将其加入到其字典序的字符串的那一组中。如果不在 map 中，则其为新的一组，并其字典序字符串为该组代表。  

## Code
```
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return vector<vector<string>>();

        string temp;
        unordered_map<string, vector<string>>strsMap;
        for(int i = 0; i < n; i++){
            temp = strs[i];
            sort(temp.begin(), temp.end());

            auto iter = strsMap.find(temp);
            if(iter != strsMap.end()){
                (iter->second).push_back(strs[i]);
            } else{
                strsMap.insert({temp, vector<string>(1, strs[i])});
            }
        }

        vector<vector<string>>result;
        for(auto iter = strsMap.begin(); iter != strsMap.end(); iter++){
            result.push_back(iter->second);
        }

        return result;
    }

};
```


## 复杂度分析
空间复杂度O(n)  
时间复杂度O(nlogn)

