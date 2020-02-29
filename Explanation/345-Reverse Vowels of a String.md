# LeetCode-345-Reverse Vowels of a String-反转字符串中的元音字母

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/345.png)

## 综述：  
\+ 使用双指针，初始为在头尾（前行，后行），头指针位置保证小于尾指针位置。头指针先行，遇到元音字母停止，到尾指针向后走，遇到元音字母停止并交换头尾指针所指内容。  

## Code
```
class Solution {
private:
    unordered_set<char>vowelSet{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
public:
    string reverseVowels(string s) {
        int len = s.size();
        if(len == 0 || len == 1) return s;

        int head = 0, tail = len - 1;
        while(head < tail){
            while(head < tail && vowelSet.count(s[head]) == 0){
                head++;
            }
            while(head < tail && vowelSet.count(s[tail]) == 0){
                tail--;
            }
            swap(s[head], s[tail]);

            head++;
            tail--;
        }

        return s;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

