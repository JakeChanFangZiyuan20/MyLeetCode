# LeetCode-165-Compare Version Numbers-比较版本号

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/165.png)

## 综述：  
\+ 按照 '.' ，将版本转换成 vector ，然后长度短的 vector 在后面补 0 ，然后两个版本逐个比较。  

## Code
```
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int str1Size = version1.size(), str2Size = version2.size();

        string part;

        vector<int>v1, v2;
        for (int i = 0; i < str1Size; i++) {
            if ('0' <= version1[i] && version1[i] <= '9') {
                part.push_back(version1[i]);
            }
            else {
                v1.push_back(stoi(part));
                part = "";
            }
        }
        v1.push_back(stoi(part));

        part = "";

        for (int i = 0; i < str2Size; i++) {
            if ('0' <= version2[i] && version2[i] <= '9') {
                part.push_back(version2[i]);
            }
            else {
                v2.push_back(stoi(part));
                part = "";
            }
        }
        v2.push_back(stoi(part));

        if (v1.size() > v2.size()) {
            int diff = v1.size() - v2.size();
            while (diff--) {
                v2.push_back(0);
            }
        }
        else {
            int diff = v2.size() - v1.size();
            while (diff--) {
                v1.push_back(0);
            }
        }

        int result = 0;
        for (int i = 0; i < v1.size(); i++) {
            if (v1[i] > v2[i]) {
                result = 1;
                break;
            }
            else if (v1[i] < v2[i]) {
                result = -1;
                break;
            }
        }

        return result;
    }
};

```


## 复杂度分析
空间复杂度O(n)  
时间复杂度O(n)

