# LeetCode-6-ZigZag Conversion-Z 字形变换

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/6.png)

## 综述：  
\+ 设立一个包含 numRows 个空 string 的数组，然后设置两个标志（row，flag）来分别控制插入到第 row 个 string 和 row 的加减。  
\+ 假设 numRows = 4，则第一到第四个字符插入到第一到第三个 string，然后第五到第六个字符插入到第三和第二个string，如此类推。  

## Code
```
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 0 || numRows == 1) return s;

        int n = s.size();
        if(n <= numRows) return s;
        vector<string>resultPart(numRows);
        int row = 0, flag = 1;
        for(int i = 0; i < n; i++){
            resultPart[row].push_back(s[i]);
            if(flag == 1) row++;
            else if(flag == 2) row--;
            if(row == numRows){
                flag = 2;
                row -= 2;
            } else if(row == -1){
                flag = 1;
                row += 2;
            }
        }
        
        for(int i = 1; i < numRows; i++){
            resultPart[0] += resultPart[i];
        }
        return resultPart[0];
    }
};
```


## 复杂度分析
空间复杂度O(n)  
时间复杂度O(n)

