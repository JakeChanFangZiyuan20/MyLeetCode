# LeetCode-93-Restore IP Addresses-复原IP地址

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/93.png)

## 综述：  
\+ 首先需要知道 IP 地址的格式。  
\+ 通过 IP 的格式知道 IP 地址分为四个部分，那么我们需要去寻找这四个部分，分析过程可看作是把三个 '.' 设置在哪三对数之间。其实通过画图可以看出这里需要使用回溯算法，因为存在多种情况（三个 '.' 的位置），但画出的树对应 IP 地址的四个部分所以只有 4 层，但每一层会有很多结果。  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/93-1.png)  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/93-2.png)  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/93-3.png)  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/93-4.png)  
\+ 上图为一例的演示过程。包括了主要判断的一些情况。。  
\+ 特殊情况：0 的存在。对于每一部分如果开头是 0，则这部分只能是长度为 1。也就是如 “123012123123” 这类情况并不能构成 IP 地址。  

## Code
```
class Solution {
private:
    string ipAddress;
    string newIPAddr;
    vector<string>result;
    vector<string>ip;
public:
    vector<string> restoreIpAddresses(string s) {
        int ipLength = s.size();
        if (ipLength < 4 || ipLength > 12) return vector<string>();

        ipAddress = s;
        ip = vector<string>(4, "");

        DFS(0, 0);

        return result;
    }

    void DFS(int part, int startPos) {
        if (startPos >= ipAddress.size()) return ; 
        if (ipAddress.size() - startPos > (4 - part) * 3) return ;
        if (part == 3) {
            string part4 = string(ipAddress.begin() + startPos, ipAddress.end());
            if (part4[0] == '0' && part4.size() > 1) return ;
            int part4Int = stoi(part4);
            if (0 <= part4Int && part4Int <= 255) {
                newIPAddr = "";
                for (int i = 0; i < 3; i++) {
                    newIPAddr += ip[i];
                    newIPAddr += ".";
                }
                newIPAddr += part4;
                result.push_back(newIPAddr);
            }
            return ;
        }

        for (int i = startPos; i < startPos + 3; i++) {
            ip[part].push_back(ipAddress[i]);
            int curPart = stoi(ip[part]);
            if (0 <= curPart && curPart <= 255) {
                DFS(part + 1, i + 1);
                ip[part + 1] = "";
            }
            if (i == startPos && ipAddress[i] == '0') return ;
        }
    }
};

```


## 复杂度分析

