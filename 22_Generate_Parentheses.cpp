/**
 * Generate Parentheses(DFS)
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        addPar(result, "", n, 0);
        return result;
    }
private:
    void addPar(vector<string>& v, string str, int n, int m) {
        if (n == 0 && m == 0) {
            v.push_back(str);
            return;
        }
        if (n > 0) addPar(v, str+"(", n-1, m+1);
        if (m > 0) addPar(v, str+")", n, m-1);
    }
};
