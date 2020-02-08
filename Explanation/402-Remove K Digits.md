# LeetCode-402-Remove K Digits-移掉k位数字

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/402.png)





## 综述：
\+ 这题参考了题解。  
\+ 当给定一个数，移除一位数使这个数最小时，需要从左向右开始遍历，获取到第一对相邻逆序数(A, B)，A > B。获取到一对逆序数后，删除第一个数。  
\+ 具体操作：  
&emsp;&emsp;\+ 从第二个字符开始遍历，检测数值是否小于前一个字符，若小于则将前一个字符删除，持续这个步骤，直到大于或等于前一个字符。  
&emsp;&emsp;\+ 对于k的说明，则等于找到k对逆序数，则等于执行k次删除操作。  
&emsp;&emsp;\+ 遍历完后对所剩字符的前置0删除。  
&emsp;&emsp;\+ 若检测到的逆序数对个数小于k，则从所剩字符按从后往前删除m个字符，m等于k减去已检测到的逆序数对个数。  

## Code
```
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k)return "0";
        int count = 0;
        string::iterator pre;
        for(string::iterator iter = num.begin() + 1; iter != num.end(); iter++){
            pre = iter - 1;
            while(iter != num.begin() && *pre > *iter){
                num.erase(pre);
                iter -= 1;
                pre = iter - 1;
                count++;
                //cout << *iter << endl;
                if(count == k) break;
            }
            if(count == k) break;
        }
        if(count != k){
            for(int i = k - count; i > 0; i--){
                num.erase(num.end() - 1);
            }
        }
        while(num.size() > 1 && *num.begin() == '0'){
            num.erase(num.begin());
        }
        return num;
    }
};
```


## 复杂度
空间复杂度O(1)  
时间复杂度O(n)
