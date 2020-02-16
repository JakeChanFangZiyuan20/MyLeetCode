# LeetCode-167-Two Sum II - Input array is sorted-两数之和 II - 输入有序数组

## 题目要求：
![avatar](https://github.com/JakeChanFangZiyuan20/MyLeetCode/blob/master/img/167.png)

## 综述：  
\+ 根据题目意思可知没有重复元素
\+ 方法一：二分  
\+ 从左向右遍历，每遍历一个数值，从该数值右方开始二分查找。  

\+ 方法二：使用map

## Code-1
```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size() == 0 || numbers.size() == 1) return vector<int>();

        vector<int>result;
        int n = numbers.size();
        for(int i = 0; i < n - 1; i++){
            result.push_back(i + 1);
            int newTarget = target - numbers[i];
            if(i == n - 2 && newTarget == numbers[i + 1]){
                result.push_back(i + 2);
                break;
            } else if(i == n - 2 && newTarget != numbers[i + 1]){
                break;
            }

            int left = i + 1, right = n - 1;
            while(left < right){
                if(numbers[left] == newTarget){
                    result.push_back(left + 1);
                    break;
                }

                if(numbers[right] == newTarget){
                    result.push_back(right + 1);
                    break;
                }

                int middle = (left + right) / 2;
                if(numbers[middle] == newTarget){
                    result.push_back(middle + 1);
                    break;
                }

                if(numbers[middle] < newTarget) left = middle;
                else right = middle;

                if(left + 1 == right) break;
            }

            if(result.size() == 2)break;
            else result.erase(result.end() - 1);
        }

        return result;
    }
};
```

## Code-2
```
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.size() == 0 || numbers.size() == 1) return vector<int>();

        vector<int>result;
        int n = numbers.size();
        map<int, int>numbersMap;
        for(int i = 0; i < n; i++){
            numbersMap[numbers[i]] = i;
        }
        for(int i = 0; i < n - 1; i++){
            int newTarget = target - numbers[i];
            map<int, int>::iterator iter = numbersMap.find(newTarget);
            if(iter != numbersMap.end()){
                result.push_back(i + 1);
                result.push_back(iter->second + 1);
                break;
            }
        }

        return result;
    }
};
```


## 复杂度分析
方法一：  
空间复杂度O(1)  
时间复杂度O(logn)

方法二：  
空间复杂度O(n)  
时间复杂度O(logn)

