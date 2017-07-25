/**
 * Remove Invalid Parentheses 
 * 
 */
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_map<string, bool> seen;
        queue<string> q;
        
        q.push(s);
        seen[s] = true;
        bool found = false;
        while (!q.empty()) {
            string str = q.front();
            q.pop();
            if (isValid(str)) {
                ans.push_back(str);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < str.size(); i++) {
                if (str[i] != '(' && str[i] != ')') continue;
                string temp = str.substr(0, i) + str.substr(i+1);
                if (seen[temp]) continue;
                q.push(temp);
                seen[temp] = true;
            }
        }
        return ans;
    }
private:
    bool isValid(string s) {
        int count = 0;
        for (auto a : s) {
            if (a == '(') count++;
            else if (a== ')') {
                if (count == 0) return false;
                count--;
            }
        }
        return count == 0;
    }
};
