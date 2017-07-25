/**
 * Expression Add Operators
 *
 */
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        dfs(ans, "", num, 0, target, 0, 0);
        return ans;
    }
private:
    void dfs(vector<string> &ans, string path, string &num, int pos, int &target, long eval, long multed) {
        // the trick is to save the value that is to be multiplied in the next recursion
        if (pos == num.size()) {
            if (eval == target) ans.push_back(path);
            return;
        }
        for (int i = pos; i < num.size(); i++) {
            if (i != pos && num[pos] == '0') break;
            string curStr = num.substr(pos, i-pos+1);
            long cur = atol(curStr.c_str());
            if (pos == 0) {
                dfs(ans, path + curStr, num, i+1, target, cur, cur);
            } else {
                dfs(ans, path + "+" + curStr, num, i+1, target, eval+cur, cur);
                dfs(ans, path + "-" + curStr, num, i+1, target, eval-cur, -cur);
                dfs(ans, path + "*" + curStr, num, i+1, target, eval - multed + multed*cur, multed*cur);
            }
        }
    }
};
