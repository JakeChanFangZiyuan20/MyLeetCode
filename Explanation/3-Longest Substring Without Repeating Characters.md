# LeetCode-3-Longest Substring Without Repeating Characters-无重复字符的最长子串

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/3.png)

## 综述：  
\+ 该题可使用快慢指针，然后结合哈希表。这题有个条件就是，无重复子串长度小于等于所给字符串中不同字符数并大于等于 1 。  
\+ 先设置快慢指针 s 和 f ，哈希表则设置为字符串中的字符为 key ，而位置为 value ，然后将各字符从第二位开始入哈希，并 value 都标为 -1。若发现哈希表中大小为 1，则直接返回 1。  
\+ 然后使用快指针向前，如果当前字符在哈希表中的 value 为 -1，证明在当前从慢指针到快指针这个子串中无重复，则快指针继续向前。  
\+ 若当前字符在哈希表中的 value 不唯一，证明当前字符在从慢指针到快指针这个子串出现过，则此时子串长度为 f - s，然后同最大长度（默认为 1）比较进行更新，然后移动慢指针到当前字符之前出现过的位置的后一位，并在慢指针移动的过程中，慢指针走过的字符在哈希表中也要恢复为 -1。当慢指针移动到当前字符之前出现过的位置的后一位，将当前字符在哈希表中记录位置。  
\+ 当快指针扫描完整个字符串，则进行最后一次 f - s 和最大长度比较并更新最大程度。  


## Code
```
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0 || n == 1) return n;

        int maxLen = 1, slow = 0, fast = 1;
        unordered_map<char, int>cMap;

        cMap[s[slow]] = slow;
        for(int i = 1; i < n; i++){
            if(cMap.count(s[i]) == 0){
                cMap[s[i]] = -1;
            }
        }
        if(cMap.size() == 1) return 1;

        for(; fast < n; fast++){
            if(cMap[s[fast]] == -1){
                cMap[s[fast]] = fast;
            } else{
                maxLen = max(maxLen, fast - slow);
                if(maxLen == cMap.size()) return maxLen;

                int pos = cMap[s[fast]];
                for(slow; slow <= pos; slow++){
                    cMap[s[slow]] = -1;
                }
                cMap[s[fast]] = fast;
            }
        }
        maxLen = max(maxLen, fast - slow);

        return maxLen;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

