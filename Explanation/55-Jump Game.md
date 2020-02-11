# LeetCode-55-Jump Game-跳跃游戏

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/55.png)

## 综述：  
\+ 使用回溯法是可以找到解的，就是从第一个元素开始把接下来的会跳到各自都跳一遍，当然会有适当的剪枝，但会需要时间比较长，因为始终会走一些不必要走的路。  
\+ 所以这里改为使用贪心算法，希望跳的步数越大，因为这样可以快点靠近最后一个点。那么对于当前点可以跳的步数为 n，那么下一步可以跳到 i+1 到 i+n 的位置，如果直接跳到 i+n 的位置，可能会直接跳到0，然后game over。所以跳多少步，即跳到哪一个位置（在满足尽量快的条件下）的选择很重要。但我们可以计算2步最远可以跳到哪里，即遍历 i+1 到 i+n 的元素，然后每遍历到一个元素进行运算nums[i+n]+i+n（n 取值从 1 到 nums[i]），会获得n个值，取最大，若为k（k 为下标，k 在 1 到 nums[i]范围内，即nums[k] + k 最大），记录最远的位置，即为从当前位置跳了一次之后，再跳一次的最远距离，然后将下一个位置更新到 k，重复这个步骤。
\+ 按照上面所说，每遍历一个i，若当前为nums[i] = 0 则返回false，若n - 1 - i <= nums[i]则返回true。
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/55-1.png)

## Code
```
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0) return false;
        if(nums.size() == 1) return true;
        
        int n = nums.size();
        for(int i = 0; i < n; ){
            if(nums[i] == 0) break;

            if(n - 1 - i <= nums[i]) return true;

            int nextPos, maxDis = -1;
            for(int j = i + 1; j <= i + nums[i]; j++){
                int curMaxDis = j + nums[j];
                if(curMaxDis > maxDis){
                    maxDis = curMaxDis;
                    nextPos = j;
                }
            }
            i = nextPos;
        }

        return false;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

