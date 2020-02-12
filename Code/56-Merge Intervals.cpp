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