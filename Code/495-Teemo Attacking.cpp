class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        if(n == 0 || duration == 0) return 0;

        int totalTime = duration;
        for(int i = 1; i < n; i++){
            if((timeSeries[i] - 1) - (timeSeries[i - 1] - 1 + duration) >= 0){ 
                totalTime += duration;
            } else{
                totalTime += 
                    (duration - ((timeSeries[i - 1] - 1 + duration) - (timeSeries[i] - 1)));
            }
        }
        return totalTime;
    }
};