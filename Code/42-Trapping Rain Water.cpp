class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0 || height.size() == 1) return 0;
        int S = 0;
        stack<int>heightStack;
        for(int i = 0; i < height.size(); i++){
            while(heightStack.size() && height[i] > height[heightStack.top()]){
                int top = heightStack.top();
                heightStack.pop();
                if(heightStack.empty()) break;
                int dis = i - heightStack.top() - 1;
                int curS = dis * (min(height[i], height[heightStack.top()]) - height[top]);
                S += curS;
            }
            heightStack.push(i);
        }
        return S;
    }
};