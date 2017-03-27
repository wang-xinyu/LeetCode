/**
 * Group Anagrams
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> map;
        for (auto s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            map[t].insert(s);
        }
        vector<vector<string>> res;
        for (auto m : map) {
            vector<string> anagram(m.second.begin(), m.second.end());
            res.push_back(anagram);
        }
        return res;
    }
};
