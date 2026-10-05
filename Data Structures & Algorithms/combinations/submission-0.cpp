class Solution {
public:
    void f(int ind, vector<int> &ds, vector<vector<int>> &ans, int k, int n, int num) {
        if(ind == k) {
            ans.push_back(ds);
            return;
        }

        for(int i = num; i <= n; i++) {
            ds.push_back(i);
            f(ind + 1, ds, ans, k, n, i + 1);
            ds.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        f(0, ds, ans, k, n, 1);
        return ans;
    }
};