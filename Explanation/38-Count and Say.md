# LeetCode-38-Count and Say-外观数列

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/1.png)

## 综述：  
\+ 按要求写代码。  

## Code
```
class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";
        for(int i = 2; i <= n; i++){
            int strSize = cur.size();
            string result("");
            for(int j = 0; j < strSize; ){
                int count = 0;
                char c = cur[j];
                while(j < strSize && c == cur[j]){
                    count++;
                    j++;
                }
                result += to_string(count);
                result.push_back(c);
            }
            cur = result;
        }
        return cur;
    }
};
```


## 复杂度分析

