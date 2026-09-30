class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<int> freq1(256, 0);
        for(char ch : s1) {
            freq1[ch]++;
        }
        int i = 0, j = 0;
        vector<int> freq(256, 0);
        while(j < n2) {
            freq[s2[j]]++;
            if(j - i + 1 == n1) {
                if(freq1 == freq)
                    return true;
                freq[s2[i]]--;
                i++;
            }
            j++;
        }
        return false;
    }
};
