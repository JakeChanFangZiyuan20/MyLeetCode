# LeetCode-383-Ransom Note-赎金信

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/383.png)

## 综述：  
\+ 使用两个 unordered_map 分别两个字符串出现过的字母以及出现次数，然后遍历 ransomNote 的 map 中的每个元素是否可以在 magzine 的 map 中存在以及出现次数是否小于等于 magzine 的 map 中的对应次数。  

## Code
```
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ranSize = ransomNote.size(), magSize = magazine.size();
        unordered_map<char, int>ranMap, magMap;
        for(int i = 0; i < ranSize; i++){
            if(ranMap.count(ransomNote[i]) == 0) ranMap[ransomNote[i]] = 1;
            else ranMap[ransomNote[i]]++;
        }
        for(int i = 0; i < magSize; i++){
            if(magMap.count(magazine[i]) == 0) magMap[magazine[i]] = 1;
            else magMap[magazine[i]]++;
        }
        for(auto iter = ranMap.begin(); iter != ranMap.end(); iter++){
            if(magMap.count(iter->first) && iter->second <= magMap[iter->first]) continue;
            else return false;
        }
        return true;
    }
};
```


## 复杂度分析
空间复杂度O(n)  
时间复杂度O(n)

