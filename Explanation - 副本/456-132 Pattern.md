# LeetCode-456-132 Pattern-132模式

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/%E6%A0%88/img/456.png)


## 综述：
\+ 该题参考了题解。  
\+ 思路：找到中间点a[j]，在a[1 - j]找min，在a[j+1 - n]找大于min小于a[j]。  
\+ 第一步：为nums每一个数cur找a[1 - cur]最小值，记录于数组min中即min数组元素于nums数组元素从下标0开始一一对应，min数组记录值为nums数组从下标0到对应值的最小值，即把nums每个值都当为a[j]，mins数组对应记录a[1 - j]最小值，完成在a[j]左方找到最小值操作。  
\+ 第二步：在a[j]右方寻找a[k]，这里使用一个栈，栈始终保持从栈顶到栈尾由小到大对nums数组从后往前遍历（设下标为i）：  
&emsp;&emsp;\+ 若nums[i] == min[i]则跳过，此时nums[i]不需要压栈的原因在nums[0 - i]中nums[i]已经最小，结合这里找a[k]，明显不符；  
&emsp;&emsp;\+ 若nums[i] > min[i]，则将栈顶元素和min[i]比较：  
&emsp;&emsp;&emsp;&emsp;\+ 若小于则出栈；  
&emsp;&emsp;&emsp;&emsp;\+ 若大于，则和nums[i]比较：  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;\+ 若小于，返回true；  
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;\+ 若大于，将nums[i]压栈；  
\+ 说明：为什么栈中元素和min比较弹出后不需要压回  
&emsp;&emsp;\+ 因为对于min[i]，min[0 - i-1] >= min[i]。所以栈顶小于min[i]的元素，一定小于min[0 - i-1]，若压回也必定会重新弹出。  
\+ 说明：若遍历到nums[i]时，栈为空，证明nums[i]后面的元素都小于此时的min[i]。

## Code
```
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size() < 3) return false;
        // 第一步
        int *min = new int[nums.size()];
        min[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < min[i - 1]){
                min[i] = nums[i];
            } else{
                min[i] = min[i - 1];
            }
        }
        // 第二步
        stack<int>NumStack;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(min[i] < nums[i]){
                while(!NumStack.empty() && NumStack.top() <= min[i]){ 
                    // 保证栈内元素都大于min[i]
                    NumStack.pop();
                }
                if(!NumStack.empty() && NumStack.top() < nums[i]){
                    return true;
                }
                NumStack.push(nums[i]);
            }
        }

        return false;
    }
};
```

## 复杂度分析
空间复杂度O(n)  
时间复杂度O(n)

