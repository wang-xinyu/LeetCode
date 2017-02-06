/**
 * Longest Valid Parentheses 
 * Use a stack to store the index of the string
 * Time complexity: O(n)
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> index;
        index.push(-1);
        int result = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '(') {
                index.push(i);
            } else if (s[i] == ')') {
                index.pop();
                if (index.empty()) {
                    index.push(i);
                } else {
                    result = max(result, i - index.top());
                }
            }
        }
        return result;
    }
};
