// 方法一
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

/*
// 方法二
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
*/