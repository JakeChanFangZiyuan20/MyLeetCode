class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return -1;
        if(n == 1){
            if(nums[0] == target) return 0;
            else return -1;
        }

        int pos = -1;
        if(nums[0] < nums[n - 1]){ // 旋转后的数组有序
            if(target < nums[0] || target > nums[n - 1]){ // 特殊情况
                return -1;
            }

            int left = 0, right = n - 1;
            while(left < right){
                if(nums[left] == target) return left;
                if(nums[right] == target) return right;

                int middle = (left + right) / 2;
                if(nums[middle] == target) return middle;
                else if(nums[middle] < target ){
                    left = middle;
                } else if(nums[middle] > target){
                    right = middle;
                }
                if(left + 1 == right) break;
            }
        } else{ // 旋转后非有序
            //  寻找旋转点
            int left = 0, right = n - 1;
            while(left < right){
                if(nums[left] == target) return left;
                if(nums[right] == target) return right;

                int middle = (left + right) / 2;
                if(nums[middle] == target) return middle;

                if(nums[middle] < nums[right]){
                    right = middle;
                } else{
                    left = middle;
                }

                if(left + 1 == right) break;
            }
            //cout << left << ',' << right << endl;;

            if(target > nums[0]){ // 0 到 left
                int a = 0, b = left;
                while(a < b){
                    if(nums[a] == target) return a;
                    if(nums[b] == target) return b;

                    int middle = (a + b) / 2;
                    //cout << nums[middle] << endl;
                    if(nums[middle] == target) return middle;
                    else if(nums[middle] < target){
                        a = middle;
                    } else{
                        b = middle;
                    }
                    
                    if(a + 1 == b) break;
                }
            } else if(target < nums[n - 1]){ // right 到 n-1
                int a = right, b = n - 1;
                while(a < b){
                    if(nums[a] == target) return a;
                    if(nums[b] == target) return b;

                    int middle = (a + b) / 2;
                    if(nums[middle] == target) return middle;
                    else if(nums[middle] < target){
                        a = middle;
                    } else{
                        b = middle;
                    }

                    if(a + 1 == b) break;
                }
            }
        }

        return pos;
    }
};