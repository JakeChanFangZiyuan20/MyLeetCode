# LeetCode-287-Find the Duplicate Number-寻找重复数

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/287.png)

## 综述：  
\+ 方法一：  
\+ 将数组排序，然后从第二个元素向后遍历，如果当前元素数值等于前一个数值，证明找到了重复数字。  
\+ 该方法不满足题目条件一：不能改变原数组

\+ 方法二：使用快慢指针  
\+ 该方法可以将数组看成一条链表，下标为节点中的数字，元素为指向的下一个元素。以上成立的原因在于，元素个数是 n + 1，证明下标取值为 0 到 n，而所个数组所有元素值都在 1 到 n 的范围内，所以可以使用任意元素值做为下标而找到另外一个元素值。那么对于没有重复数字的数组，例如 [4,1,3,2] 可构成：  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/287-1.png)
\+ 由此推知，对于没有重复数字的数组可构成一条没有环的链，因为每个元素只有唯一的下标对应，即严格符合一一对应关系。  
\+ 那么对于一个存在重复数字的数组，就会存在多个下标指向同一元素的情况，如果对该数组构造链，该链就会有存在环，并且环的入口就是那个重复的数字，因为有多个下标指向该数字。  
\+ 综上所述，我们可以使用快慢指针像在链表中找到环的进口那样在数组中找到重复数字。对于快慢指针总会在环状内部相遇以及找到环状入口点的证明参考[LeetCode142.环状链表II](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/Explanation/142-Linked%20List%20CycleII.md)。  


## Code-1
```
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 排序时间复杂度O(nlogn)
        int n = nums.size(), result;
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i - 1]){
                result = nums[i];
                break;
            }
        }
        return result;
    }
};
```

## Code-2
```
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, n = nums.size();
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                fast = 0;
                while(slow != fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                break;
            }
        }
        return slow;
    }
};
```


## 复杂度分析
方法一：  
空间复杂度O(1)  
时间复杂度O(nlogn)  

方法二：  
空间复杂度O(1)  
时间复杂度O(n)

