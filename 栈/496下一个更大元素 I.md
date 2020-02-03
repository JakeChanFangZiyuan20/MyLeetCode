# LeetCode-496-Next Greater Element I-下一个更大元素 I

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/%E6%A0%88/img/496.png)

## 综述：  
\+ 该题参考了题解，还有很长的一段路要走。  
&emsp;&emsp;\+ 建立一个栈和一个map。  
&emsp;&emsp;\+ 遍历num2：  
&emsp;&emsp;&emsp;&emsp;\+ 若栈空，则直接入栈。  
&emsp;&emsp;&emsp;&emsp;\+ 若栈不空，则当前元素和栈顶元素比较：  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;\+ 若小于，则直接入栈。  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;\+ 若大于，则map[栈顶元素] = 当前元素，然后当前元素入栈。  
&emsp;&emsp;\+ 遍历完成后若栈不空，则站内元素逐个出栈并map[栈顶元素] = -1。  
&emsp;&emsp;\+ 遍历num1，以num1元素为key，从map中获得对应value，逐个放入一个vector\<int>中即为结果。

## Code
```
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        if(nums1.size() == 0) return result;
        stack<int>NumStack;
        map<int ,int>NumPair;
        for(vector<int>::iterator iter = nums2.begin(); iter != nums2.end(); ){
            if(!NumStack.empty() && *iter > NumStack.top()){
                NumPair[NumStack.top()] = *iter;
                NumStack.pop();
            } else{
                NumStack.push(*iter);
                iter++;
            }
        }
        while(!NumStack.empty()){
            NumPair[NumStack.top()] = -1;
            NumStack.pop();
        }
        for(vector<int>::iterator iter = nums1.begin(); iter != nums1.end(); iter++){
            result.push_back(NumPair[*iter]);
        }
        return result;
    }
};
```

## 复杂度分析
时间复杂度O(m+n)  
空间复杂度O(n)
