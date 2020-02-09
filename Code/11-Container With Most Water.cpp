class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxS = 0;
        while(i < j){
            int curS = min(height[i], height[j]) * (j - i);
            if(curS > maxS) maxS = curS;
            if(height[i] < height[j]) i++;
            else j--;
        }
        return maxS;
    }
};