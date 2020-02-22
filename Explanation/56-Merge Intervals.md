# LeetCode-56-Merge Intervals-合并区间

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/56.png)

## 综述：  
\+ 先将每个区间按区间的左边界从小到大排序，然后逐个合并。  

## Code
```
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return vector<vector<int>>();

        sort(intervals.begin(), intervals.end(), comp);
        
        vector<vector<int>>result;
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ){
            int a1 = intervals[i][0], a2 = intervals[i][1];
            int b1 = (*(result.end() - 1))[0], b2 = (*(result.end() - 1))[1];

            if(a1 == b1 && a2 == b2){
                i++;
                continue;
            }

            if(a2 < b1 || b2 < a1){
                result.push_back(intervals[i]);
                i++;
                continue;
            }
            
            (*(result.end() - 1))[0] = min(a1, b1);
            (*(result.end() - 1))[1] = max(a2, b2);
            i++;
        }
        return result;
    }

    static bool comp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
};
```


## 复杂度分析
空间复杂度O(1) ~ O(n)  
时间复杂度O(nlogn)

