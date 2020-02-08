class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>result;
        if(nums1.size() == 0) return result;
        stack<int>NumStack;
        map<int ,int>NumPair;
        for(vector<int>::iterator iter = nums2.begin(); iter != nums2.end(); ){
            if(!NumStack.empty() && *iter > NumStack.top()){
                NumPair[NumStack.top()] = *iter;
                NumStack.pop();
            } else{
                NumStack.push(*iter);
                iter++;
            }
        }
        while(!NumStack.empty()){
            NumPair[NumStack.top()] = -1;
            NumStack.pop();
        }
        for(vector<int>::iterator iter = nums1.begin(); iter != nums1.end(); iter++){
            result.push_back(NumPair[*iter]);
        }
        return result;
    }
};