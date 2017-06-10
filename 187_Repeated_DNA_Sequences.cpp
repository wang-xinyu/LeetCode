/**
 * Repeated DNA Sequences
 *
 */
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_map<string, int> map;
        vector<string> ans;
        for (int i = 0; i <= n-10; i++) {
            string str = s.substr(i, 10);
            if (map[str] == 1) ans.push_back(str);
            map[str]++;
        }
        return ans;
    }
};
