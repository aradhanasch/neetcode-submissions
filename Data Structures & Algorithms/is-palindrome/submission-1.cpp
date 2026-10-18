class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int st = 0, end = n - 1;
        while(st < end) {
            if(!isalnum(s[st]))
                st++;
            else if(!isalnum(s[end]))
                end--;
            else if(tolower(s[st]) != tolower(s[end]))
                return false;
            else {
                st++;
                end--;
            }
        }
        return true;
    }
};
