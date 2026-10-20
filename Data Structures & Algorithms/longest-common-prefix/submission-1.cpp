class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        for(int j = 0; j < strs[0].size(); j++) {
            char ch = strs[0][j];
            for(int i = 0; i < n; i++) {
                if(j >= strs[i].size() || strs[i][j] != ch)
                    return ans;
                if(i == n - 1)
                    ans = strs[0].substr(0, j + 1);
            }
        }
        return ans;
    }
};