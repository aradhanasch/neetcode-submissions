class Solution {
public:
    string minWindow(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        vector<int> freqT(256, 0);
        vector<int> freq(256, 0);
        for(char ch : t) {
            freqT[ch]++;
        }
        int cnt = 0;
        int start = 0;
        int i = 0, j = 0;
        int ans = INT_MAX;
        while(j < n1) {
            freq[s[j]]++;
            if(freq[s[j]] <= freqT[s[j]])
                cnt++;
            while(cnt == n2) {
                if(ans > j - i + 1) {
                    ans = j - i + 1;
                    start = i;
                }
                if(freq[s[i]] <= freqT[s[i]])
                    cnt--;
                freq[s[i]]--;
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? "" : s.substr(start, ans);
    }
};
