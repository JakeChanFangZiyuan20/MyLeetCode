# LeetCode-457-Circular Array Loop-环形数组循环

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/457.png)

## 综述：  
\+ 本题从快慢指针入手，从左向右开始遍历，以每一个点为开始点，然后进行快慢指针向前，如果快慢指针相遇，则证明有环。对于环的长度是否为 1 的话，则在更新快指针时检测。由于这里快指针采取跳两次的模式，则跳一次和跳第二次如果都是同一位置，则证明该循环无效。对于方向，则在每次更新快慢指针的时候进行更新后的位置和更新前的位置进行比较检测，如果符号不同则存在方向相反。

## Code
```
class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return false;
        bool result = false;
        for(int i = 0; i < n; i++){
            int slow = i, fast = i;
            bool reverse = false, loopOfOne = false;
            do{
                int lastSlow = slow;

                if(abs(nums[slow]) % n != 0){
                    int nextSlow = slow + nums[slow];
                    if(0 <= nextSlow && nextSlow <= n - 1) slow = nextSlow;
                    else if(nextSlow < 0) slow = n - abs(nextSlow) % n;
                    else slow = abs(nextSlow) % n;
                }

                if(nums[lastSlow] > 0 && nums[slow] <0 || 
                        nums[lastSlow] < 0 && nums[slow] > 0){
                    reverse = true;
                    break;
                }
                
                int lastFast;
                for(int k = 1; k <= 2; k++){
                    lastFast = fast;

                    if(abs(nums[fast]) % n != 0){
                        int nextFast = fast + nums[fast];
                        if(0 <= nextFast && nextFast <= n - 1) fast = nextFast;
                        else if(nextFast < 0) fast = n - abs(nextFast) % n;
                        else fast = abs(nextFast) % n;
                    }

                    if(nums[lastFast] > 0 && nums[fast] <0 || 
                            nums[lastFast] < 0 && nums[fast] > 0){
                        reverse = true;
                        break;
                    }
                }
                if(reverse) break;

                if(lastFast == fast){
                    loopOfOne = true;
                    break;
                }
                
            }while(slow != fast);

            if(reverse || loopOfOne) continue;

            result = true;
            break;
        }
        return result;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

