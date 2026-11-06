class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++) {
            string ch = tokens[i];
            if(ch == "+" || ch == "-" || ch == "*" || ch == "/") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                int res;
                if(ch == "+")
                    res = b + a;
                else if(ch == "-")
                    res = b - a;
                else if(ch == "*")
                    res = b * a;
                else
                    res = b / a;
                s.push(res);
            } else {
                s.push(stoi(ch));
            }
        }
        return s.top();
    }
};
