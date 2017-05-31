/**
 * Evaluate Reverse Polish Notation
 *
 */ 
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> v;
        int a, b;
        int c;
        for (auto t : tokens) {
            if (t == "+" || t == "-" || t == "*" || t == "/") {
                b = atoi(v.top().c_str());
                v.pop();
                a = atoi(v.top().c_str());
                v.pop();
            } else {
                v.push(t);
                continue;
            }
            if (t == "+") c = a + b;
            else if (t == "-") c = a - b;
            else if (t == "*") c = a * b;
            else if (t == "/") c = a / b;
            v.push(to_string(c));
        }
        return atoi(v.top().c_str());
    }
};
