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