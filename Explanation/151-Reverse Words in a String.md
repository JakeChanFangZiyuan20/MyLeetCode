# LeetCode-151-Reverse Words in a String-翻转字符串里的单词

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/151.png)

## 综述：  
\+ 按要求写代码。  

## Code
```
class Solution {
public:
    string reverseWords(string s) {
        int strSize = s.size();
        if (strSize == 0) return s;

        int count_temp = 2;
        while (count_temp--) {
            for (auto iter = s.begin(); iter != s.end(); ) {
                if (*iter == ' ') s.erase(iter);
                else if (*iter != ' ') break;
            }
            if(count_temp == 1)reverse(s.begin(), s.end());
        }

        for (auto iter = s.begin(); iter != s.end(); ) {
            if (*iter == ' ' && *(iter - 1) == ' ') s.erase(iter);
            else {
                auto iter2 = iter;
                while (iter2 != s.end() && *(iter2) != ' ') {
                    iter2++;
                }

                reverse(iter, iter2);
                if (iter2 == s.end()) break;
                iter = iter2 + 1;
            }
        }

        if (*(s.begin()) == ' ') s.erase(s.end() - 1);

        return s;
    }
};

```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

