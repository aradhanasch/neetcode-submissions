class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int mx = 0;
        for(int i = 0; i < n; i++) {
            vector<int> freq(256, 0);
            for(int j = i; j < n; j++) {
                freq[s[j]]++;
                if(freq[s[j]] != 1) {
                    break;
                }
                mx = max(mx, j - i + 1);
            }
        }
        return mx;
    }
};
