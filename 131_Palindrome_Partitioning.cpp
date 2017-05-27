/**
 * Palindrome Partitioning
 * DFS
 */
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        if (s.empty()) return ans;
        vector<string> partition;
        dfs(ans, s, partition, 0);
        return ans;
    }
private:
    void dfs(vector<vector<string>> &ans, string &s, vector<string> &partition, int start) {
        if (start == s.size()) {
            ans.push_back(partition);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            string str = s.substr(start, i-start+1);
            if (isPalindrome(str)) {
                partition.push_back(str);
                dfs(ans, s, partition, i+1);
                partition.pop_back();
            }
        }
    }
    bool isPalindrome(string str) {
        int i = 0, j = str.size()-1;
        while (i < j) {
            if (str[i] != str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
