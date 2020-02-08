# LeetCode-71-Simplify Path-简化路径

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/71.png)






## 综述：  
将两个“/”间的字符串提取：  
1、若为“.”，则不需操作，因为仍未本目录内。  
2、若为“..”，则看栈是否为空，为空则不需操作，不为空则弹出栈顶元素。  
3、若为一串字符串则直接入栈。  
  
以上说明可用vector作为栈  
在vector从头扫描时，每扫描一个元素在其前加“/”，然后进行拼接。  

## Code
```
class Solution {
public:
    string simplifyPath(string path) {
        if(path.size() == 0) return "";
        if(path.size() == 1) return "/";
        
        string element;
        vector<string>stdpath;
        int num = path.size();
        for(int i = 0; i < num; ){
            if(path[i] == '/') {
                i += 1;
            } else{
                element = "";
                for(int j = i; j < num ; j++){
                    if(path[j] == '/') break;
                    element.push_back(path[j]);
                }
                // element == "."，无任何变化，直接i += 1
                if(element == "."){}
                else if(element == ".."){
                    if(stdpath.size() != 0) stdpath.pop_back();
                } else{
                    stdpath.push_back(element);
                }
                i += element.size();
            }
        }

        string resultpath("");
        num = stdpath.size();
        for(int i = 0; i< num; i++){
            resultpath += "/";
            resultpath += stdpath[i];
        }

        if(resultpath.size() == 0) resultpath = "/";
        return resultpath;
    }
};
```

## 复杂度分析
空间复杂度O(n)  
时间复杂度O(n)

