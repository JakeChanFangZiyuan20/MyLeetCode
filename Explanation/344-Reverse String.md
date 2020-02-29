# LeetCode-344-Reverse String-反转字符串

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/344.png)

## 综述：  
\+ 双指针初始指向头尾，交换后头指针向前，尾指针向后，头指针位置始终小于尾指针位置。  

## Code
```
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        if(len == 0 || len == 1) return ;

        int head = 0, tail = len - 1;
        while(head < tail){
            char temp_c = s[head];
            s[head] = s[tail];
            s[tail] = temp_c;

            head++;
            tail--;
        }

    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

