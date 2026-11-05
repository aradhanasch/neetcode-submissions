class Solution {
public:
    bool isValid(string st) {
        stack<char> s;
        for(char ch : st) {
            if(ch == '(' || ch == '[' || ch == '{') {
                s.push(ch);
            } else {
                if(!s.empty()) {
                    if(ch == ')' && s.top() == '(')
                        s.pop();
                    else if(ch == ']' && s.top() == '[')
                        s.pop();
                    else if(ch == '}' && s.top() == '{')
                        s.pop();
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        return s.empty();
    }
};
