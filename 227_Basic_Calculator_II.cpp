/**
 * Basic Calculator II 
 *
 */
class Solution {
public:
    int calculate(string s) {
        for (int i = 0; i < s.size();) {
            if (s[i] == ' ') s.erase(s.begin()+i);
            else i++;
        }
        stack<char> v;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*' && s[i] != '/') v.push(s[i]);
            else {
                int num1 = 0, in = 1, j, num2 = 0;
                while (!v.empty() && v.top() >= '0' && v.top() <= '9') {
                    num1 += in*(v.top() - '0');
                    v.pop();
                    in *= 10;
                }
                for (j = i+1; j < s.size() && s[j] >= '0' && s[j] <= '9'; j++) {
                    num2 = 10*num2 + (s[j] - '0');
                }
                int num = (s[i] == '*') ? num1*num2 : num1/num2;
                string str = to_string(num);
                for (auto c : str) v.push(c);
                i = j-1;
            }
        }
        int sum = 0;
        while (!v.empty()) {
            int num = 0, in = 1;
            while (!v.empty() && v.top() >= '0' && v.top() <= '9') {
                num += in*(v.top() - '0');
                v.pop();
                in *= 10;
            }
            if (!v.empty() && v.top() == '-') num = -num;
            if (!v.empty()) v.pop();
            sum += num;
        }
        return sum;
    }
};
