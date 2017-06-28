/**
 * Basic Calculator
 *
 */
class Solution {
public:
    int calculate(string s) {
        int sum = 0;
        stack<char> v;
        for (int i = 0; i < s.size();) {
            if (s[i] == ' ') s.erase(s.begin()+i);
            else i++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ')') v.push(s[i]);
            else {
                int localsum = 0;
                while (v.top() != '(') {
                    int num = 0, in = 1;
                    while (!v.empty() && v.top() >= '0' && v.top() <= '9') {
                        num += in*(v.top()-'0');
                        in *= 10;
                        v.pop();
                    }
                    if (!v.empty() && v.top() == '-') num = -num;
                    if (!v.empty() && v.top() != '(') v.pop();
                    localsum += num;
                }
                v.pop();
                if ((!v.empty() && v.top() == '-')) localsum = -localsum;
                if (!v.empty()) v.pop();
                v.push(localsum >= 0 ? '+' : '-');
                string temp = to_string(abs(localsum));
                for (char c : temp) v.push(c);
            }
        }
        while (!v.empty()) {
            int num = 0, in = 1;
            while (!v.empty() && v.top() >= '0' && v.top() <= '9') {
                num += in*(v.top()-'0');
                in *= 10;
                v.pop();
            }
            if (!v.empty() && v.top() == '-') num = -num;
            if (!v.empty()) v.pop();
            sum += num;
        }
        return sum;
    }
};
