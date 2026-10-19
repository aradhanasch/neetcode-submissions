class Solution {
public:
    bool help(string &s, int st, int end) {
        while(st < end) {
            if(s[st] != s[end])
                return false;
            else {
                st++;
                end--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int st = 0, end = s.length() - 1;
        while(st < end) {
            if(s[st] != s[end]) 
                return help(s, st + 1, end) || help(s, st, end - 1);
            else {
                st++;
                end--;
            }
        }
        return true;
    }
};