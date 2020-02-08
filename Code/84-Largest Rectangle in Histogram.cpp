class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0) return 0;
        int maxS = 0;
        stack<int>hs;
        hs.push(-1);
        for(int i = 0; i < heights.size(); i++){
            while(hs.top() != -1 && heights[hs.top()] > heights[i]){
                int top = hs.top();
                hs.pop();
                maxS = max(maxS, heights[top] * (i - hs.top() - 1)); // 面积
            }
            hs.push(i);
        }
        while(hs.top() != -1){
            int top = hs.top();
            hs.pop();
            maxS = max(maxS, (int)(heights[top] * (heights.size() - hs.top() - 1))); //面积
        }
        return maxS;
    }
};