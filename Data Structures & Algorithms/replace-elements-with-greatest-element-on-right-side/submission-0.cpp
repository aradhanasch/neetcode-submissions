class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        int mx = -1;
        for(int i = n - 2; i >= 0; i--) {
            mx = max(mx, arr[i + 1]);
            ans[i] = mx;
        }
        return ans;
    }
};