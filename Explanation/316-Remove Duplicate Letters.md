# LeetCode-316-Remove Duplicate Letters-去除重复字母

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/316.png)





## 综述：  
\+ 思路：符合字典序，则为a-z从小到大，使用栈，压栈时尽量保持从栈尾到栈顶由小到大。但要符合原字符串的字符相对顺序，并删除重复字母。则压栈时检测栈顶是否大于当前字符，若大于，则检测当前字符后是否还有栈顶字符，若还有，则将栈顶字符弹出。直到栈为空或者栈顶字符小于当前字符或者栈顶字符大于当前字符但当前字符后已经没有栈顶字符时，将栈顶字符压入栈。但遍历到每个字符时，若栈中已有当前字符，则跳过。  
\+ 建立两个map，key都为'a'到'z'，map1记录s中字符出现次数（也为还未遍历字符串中字符出现个数），map2记录该字符是否入栈。  
\+ 遍历s：  
&emsp;&emsp;\+ 若当前字符为已出现在栈中（counts2[c] == 1），则counts[c] - 1；  
&emsp;&emsp;\+ 若当前栈空或者当前字符大于栈顶字符，则将该字符入栈，并counts2[c] = 1；
&emsp;&emsp;\+ 若当前字符小于栈顶字符：  
&emsp;&emsp;&emsp;&emsp;\+ 判断栈顶字符counts[stack.top]是否大于1（判断未遍历字符串是否还存在该字符）：  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;\+ 若大于，则counts[stack.top]-1，counts2[stack.top]=0，并出栈；  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;\+ 若小于，则当前字符入栈，并counts2[c]=1；  

## Code
```
class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.size() == 0 || s.size() == 1) return s;
        map<char, int>counts;
        map<char, int>counts2;
        for(char c = 'a'; c <= 'z'; c++){
            counts[c] = 0;
            counts2[c] = 0;
        }
        for(string::iterator iter = s.begin(); iter != s.end(); iter++){
            counts[*iter]++;
        }

        string CStack;
        for(string::iterator iter = s.begin(); iter != s.end(); iter++){
            if(counts2[*iter] == 1){
                counts[*iter]--;
                continue;
            } else if(CStack.size() == 0 || *iter > *(CStack.end() - 1)){
                CStack.push_back(*iter);
                counts2[*iter] = 1;
            } else if(*iter < *(CStack.end() - 1)){
                if(counts[*(CStack.end() - 1)] > 1){
                    counts[*(CStack.end() - 1)]--;
                    counts2[*(CStack.end() - 1)] = 0;
                    CStack.erase(CStack.end() - 1);
                    iter--;
                } else{
                    CStack.push_back(*iter);
                    counts2[*iter] = 1;
                }
            }
        }
        return CStack;
    }
};
```

## 复杂度分析
时间复杂度O(n)  
空间复杂度O(n)
