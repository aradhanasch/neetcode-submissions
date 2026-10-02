class Solution {
public:
    void f(int i, string &ds, int open, int close, vector<string> &ans, int n) {
        if(i == 2 * n) {
            ans.push_back(ds);
            return;
        }

        if(open < n) {
            ds.push_back('(');
            f(i + 1, ds, open + 1, close, ans, n);
            ds.pop_back();
        }

        if(close < open) {
            ds.push_back(')');
            f(i + 1, ds, open, close + 1, ans, n);
            ds.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string ds;
        f(0, ds, 0, 0, ans, n);
        return ans;
    }
};
