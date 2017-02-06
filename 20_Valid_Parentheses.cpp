/**
 * Valid Parenttheses
 * Time complexity: O(n)
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> par;
        for (int i = 0; s[i] != '\0'; i++) {
            switch (s[i]) {
                case '(':
                case '[':
                case '{':
                    par.push(s[i]);
                    break;
                case ')':
                    if (par.empty() || par.top() != '(') return false;
                    par.pop();
                    break;
                case ']':
                    if (par.empty() || par.top() != '[') return false;
                    par.pop();
                    break;
                case '}':
                    if (par.empty() || par.top() != '{') return false;
                    par.pop();
                    break;
                default:
                    break;
            }
        }
        return par.empty();
    }
};
