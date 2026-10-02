class Solution {
public:
    void f(int ind, vector<int> &c, int target, vector<int> &ds, vector<vector<int>> &ans) {
        if(target == 0) {
            ans.push_back(ds);
            return;
        }
        
        for(int i = ind; i < c.size(); i++) {
            if(i != ind && c[i] == c[i - 1]) 
                continue;
            if(c[i] > target)
                break;
            ds.push_back(c[i]);
            f(i + 1, c, target - c[i], ds, ans);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        sort(c.begin(), c.end());
        vector<vector<int>> ans;
        vector<int> ds;
        f(0, c, target, ds, ans);
        return ans;
    }
};
