# LeetCode-443-String Compression-压缩字符串

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/443.png)

## 综述：  
\+ 这里使用三个指针来操作。  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/443-1.png)  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/443-2.png)  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/443-3.png)  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/443-4.png)  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/443-5.png)  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/443-6.png)  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/443-7.png)  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/443-8.png)  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/443-9.png)  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/443-10.png)  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/443-11.png)  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/443-12.png)  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/443-13.png)  


## Code
```
class Solution {
public:
    int compress(vector<char>& chars) {
        int len = chars.size();
        if(len == 0) return len;

        int i = 0, j = 0, k = 0;
        string curSum;
        for(i; i < len && j < len; ){
            i = j;
            while(j < len && chars[j] == chars[i]){
                j++;
            }
            k++;
            if(j - i >= 2){
                curSum = to_string(j - i);
                for(int pos = 0; pos < curSum.size(); pos++){
                    chars[k++] = curSum[pos];
                }
            }
            if(j < len) chars[k] = chars[j];
        }

        return k;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

