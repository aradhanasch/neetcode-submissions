class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freqS(26,0);
        vector<int>freqT(26,0);
        if(s.length()!=t.length())  return false;
        for(int i=0;i<s.length();i++){
            freqS[s[i]-'a']++;
            freqT[t[i]-'a']++;
        }
        if(freqS==freqT)    return true;
        else    return false;
    }
};
