/**
 * Isomorphic Strings
 *
 */
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map1, map2;
        for (int i = 0; i < s.size(); i++) {
            if (map1.count(s[i])) {
                if (t[i] != map1[s[i]]) return false;
            } else if (map2.count(t[i])) {
                if (s[i] != map2[t[i]]) return false;
            } else {
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            }
        }
        return true;
    }
};
