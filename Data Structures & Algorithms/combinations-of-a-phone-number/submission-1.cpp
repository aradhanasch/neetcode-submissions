class Solution {
public:
    void f(int ind, vector<string> &ds, vector<string> &ans, int n, string &st) {
        if(ind == n) {
            ans.push_back(st);
            return;
        }

        for(int i = 0; i < ds[ind].length(); i++) {
            st.push_back(ds[ind][i]);
            f(ind + 1, ds, ans, n, st);
            st.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        vector<string> ans;
        if(n == 0)
            return ans;
        vector<string> vec = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ds;
        for(char ch : digits) {
            ds.push_back(vec[ch - '2']);
        }
        string st;
        f(0, ds, ans, n, st);
        return ans;
    }
};
