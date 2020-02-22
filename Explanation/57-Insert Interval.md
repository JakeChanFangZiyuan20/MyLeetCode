# LeetCode-57-Insert Interval-插入区间

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/57.png)

## 综述：  
\+ 该题在[LeetCode56.合并区间](https://leetcode-cn.com/problems/merge-intervals/)的基础之上，但题目比较友好，把所给的区间排好序以及无重叠，那么只需按照每个区间的首端排序将所给区间插入然后进行合并即可。  

## Code
```
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n1= intervals.size(), n2 = newInterval.size();
        if(n1 == 0){ 
            intervals.push_back(newInterval);
            return intervals;
        }
        if(n2 == 0) return intervals;

        for(auto iter = intervals.begin(); iter != intervals.end(); iter++){
            if((*iter)[0] > newInterval[0]){
                intervals.insert(iter, newInterval);
                break;
            }
        }
        if(intervals.size() == n1) intervals.push_back(newInterval);

        vector<vector<int>>result;
        for(auto iter = intervals.begin(); iter != intervals.end(); iter++){
            if(result.size() == 0) result.push_back(*iter);
            else{
                auto iter2 = result.end() - 1;
                if((*iter2)[1] >= (*iter)[0]) (*iter2)[1] = max((*iter)[1], (*iter2)[1]);
                else result.push_back(*iter);
            }
        }
        return result;
    }
};
```


## 复杂度分析
空间复杂度O(1)  
时间复杂度O(n)

