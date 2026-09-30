class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        vector<int> freq1(256, 0);
        for(char ch : s1) {
            freq1[ch]++;
        }
        for(int i = 0; i <= n2 - n1; i++) {
            vector<int> freq2(256, 0);
            for(int j = i; j < i + n1; j++) {
                freq2[s2[j]]++;
            }
            if(freq1 == freq2)
                return true;
        }
        return false;
    }
};
