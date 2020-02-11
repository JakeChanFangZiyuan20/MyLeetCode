# LeetCode-45-Jump Game II-跳跃游戏 II

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/45.png)

## 综述：  
\+ 该题方法基本同[LeetCode45.跳跃游戏 II](https://leetcode-cn.com/problems/jump-game-ii/)，可参考[跳跃游戏 II](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/Explanation/45-Jump%20Game%20II.md)，主要不同在于，这里题目说明一定可以跳到最后一个位置，所以不需要判断不成功的那些代码，然后就是每到一个位置计数加 1 ，最后返回总计数。  

## Code
```
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        
        int n = nums.size(), count = 0;
        for(int i = 0; i < n; ){
            count += 1;
            if(n - 1 - i <= nums[i]) return count;

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

        return count;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

