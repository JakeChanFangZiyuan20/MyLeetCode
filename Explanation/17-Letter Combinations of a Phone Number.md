# LeetCode-17-Letter Combinations of a Phone Number-电话号码的字母组合

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/17.png)

## 综述：  
\+ 递归，枚举出所有可能，每一个可能都是其中一个解，所以直接加入到结果数组中。

## Code
```
class Solution {
private:
    unordered_map<char, string>button = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string>result;
    string newGroup;
    int digitsLen;
    string digits;
public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        digitsLen = digits.size();

        DFS(0);

        return result;
    }

    void DFS(int pos){
        if(pos == digitsLen) return ;
        if(pos == digitsLen - 1){
            for(int i = 0; i < button[digits[pos]].size(); i++){
                newGroup.push_back(button[digits[pos]][i]);
                result.push_back(newGroup);
                newGroup.pop_back();
            }
            return ;
        }
        for(int i = 0; i < button[digits[pos]].size(); i++){
            newGroup.push_back(button[digits[pos]][i]);
            DFS(pos + 1);
            newGroup.pop_back();
        }
    }
};
```


## 复杂度分析
空间复杂度O(3<sup>N</sup> * 4<sup>M</sup>)  
时间复杂度O(3<sup>N</sup> * 4<sup>M</sup>)  
N，对应有三个字母的数字；M，对应有四个字母的数字。  

