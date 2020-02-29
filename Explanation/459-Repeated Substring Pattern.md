# LeetCode-459-Repeated Substring Pattern-重复的子字符串

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/459.png)

## 综述：  
\+ 方法一：暴力  
\+ 使用 sub 为（0，i）的子串，然后考察其长度是否为总长的因数，若是则乘以相应的倍数构成与原字符串一样长的字符串，然后比较两字符串是否相同。  

\+ 方法二：该方法参考题解  
\+ 假设原字符串 s 由 n 个子串 x 重复构成。设 t 字符串由两个 s 构成（存在 2n 个 子串 x ）。此时去除首尾字符构成字符串 t' ，内含 2n - 2 个 x。若 t' 中还包含至少一个 s ，则 2n - 2 >= n ，即 n >= 2，说明 s 是由 x 重复多次构成。若 t' 中还不包含 s ，则  2n - 2 < n ，即 n < 2 ，说明 s 由 x 重复 0 或 1 次构成。  

## Code-1
```
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        if(len == 0) return false;

        bool result = false;
        string sub, rebuild;
        int subLen, times;
        for(int i = 0; i < len; i++){
            sub = s.substr(0, i + 1);
            subLen = sub.size();

            if(subLen > len / 2) break;

            if(len % subLen == 0){
                times = len / subLen;
                rebuild = "";
                while(times--){
                    rebuild += sub;
                }
                if(rebuild == s) return true;
            }
        }
        return result;
    }
};
```

## Code-2
```
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.size() == 0) return false;
        string t = s + s;
        t = t.substr(1, 2 * s.size() - 2);
        if(t.find(s) == -1) return false;
        return true; 
    }
};
```

## 复杂度分析
方法一：  
空间复杂度O(n)  
时间复杂度O(n<sup>2</sup>)  

方法二：  
空间复杂度O(n)  
时间复杂度O()  


