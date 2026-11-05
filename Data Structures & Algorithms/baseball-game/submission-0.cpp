class Solution {
public:
    int calPoints(vector<string>& ops) {
        int n = ops.size();
        stack<int> s;
        for(int i = 0; i < n; i++) {
            if(ops[i] == "C") {
                s.pop();
            } else if(ops[i] == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                int c = a + b;
                s.push(a);
                s.push(c);
            } else if(ops[i] == "D") {
                int a = 2 * s.top();
                s.push(a);
            } else {
                s.push(stoi(ops[i]));
            }
        }
        int sum = 0;
        while(!s.empty()) {
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};