class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int i = 0, j = n - 1;
        int ans = 0;
        while(i < j) {
            ans = max(ans, (min(heights[i], heights[j])) * (j - i));
            if(heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }
        return ans;
    }
};
