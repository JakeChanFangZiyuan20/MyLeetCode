# LeetCode-621-Task Scheduler-任务调度器

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/621.png)





## 综述：  
\+ 该题参考题解。  
\+ 一开始没有寻找规律，直接模拟，结果一直不为最小。  
\+ 为了总时间最短，最好先将出现次数最多的任务执行。
\+ 例如"AAAABBBCCEEE, n = 2"中，先执行最多的A，则"A--A--A--A"，其中'-'为间隔，那么剩余未执行的任务插空即可。  
\+ 以下做出二维图：  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/621-1.png)




\+ 从上方二维图可以按出，先执行次数最多的任务（max次），则会产生(max - 1) * n个空闲位置idle，剩余任务插空即可。  
\+ 若idle数小于任务总数减去上图最左一列的任务数（即tasks.size() - max），则返回tasks.size()，若大于则返回(max - 1) + idle + maxNum。  
\+ 若存在两个或两个以上任务需要执行次数相同，则有下图：  
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/img/img/621-2.png)




\+ 则任务总数减去上图最左一列和最后一行的任务后，再和idle比较。  

## Code
```
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
```

## 复杂度分析
时间复杂度O(n)
空间复杂度O(1)