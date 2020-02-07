class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();
        int taskNum[26] = {0};
        for(int i = 0; i < tasks.size(); i++){
            taskNum[tasks[i] - 'A']++;
        }
        sort(taskNum, taskNum + 26);
        int max = taskNum[25], maxNum = 0, idle = (max - 1) * n;
        for(int i = 25; i >= 0; i--){
            if(taskNum[i] == max){
                maxNum++;
            } else{
                break;
            }
        }
        int totalTime = 0;
        if(idle > tasks.size() - (max - 1) - maxNum){
            totalTime = (max - 1) + idle + maxNum;
        } else{
            totalTime = tasks.size();
        }
        return totalTime;
    }
};