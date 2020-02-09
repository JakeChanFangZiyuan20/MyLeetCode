# LeetCode-16-3Sum Closet-最接近的三数之和

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/16.png)

## 综述：  
\+ 本题在[LeetCode15.三数之和](https://leetcode-cn.com/problems/3sum/)解法相近，主要区别在于查找与target值最近的三数和。  
\+ 同样是先排序（元素总数为n），然后从左向右遍历，遍历i然后确定其右数值的左右边界（i+1和n-1），三数相加获得cur，然后abs(cur - target)和abs(res- target)两个距离进行比较，取小更新res，若cur=target直接返回target，若cur < target则左边界向右，若cur > target则右边界向左，注意避免重复元素。

## Code
```
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = 0;
        int n = nums.size();
        if(n < 3) return res;

        sort(nums.begin(), nums.end());

        res = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < n - 2; i++){
            int l = i + 1, r = n - 1;
            while(l < r){
                int cur = nums[i] + nums[l] + nums[r];
                if(cur == target) return target;
                
                //比较距离
                if(abs(res - target) > abs(cur - target)){
                    res = cur;
                }
                if(cur < target){
                    int templ = nums[l];
                    while(l < r && nums[l] == templ) l++;
                } else{
                    int tempr = nums[r];
                    while(r > l && nums[r] == tempr) r--;
                }
            }
        }
        return res;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n<sup>2</sup>)

