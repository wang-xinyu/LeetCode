/**
 * Word Pattern
 * 
 */
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.empty()) return str.empty();
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        int start = 0;
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            int end = start;
            while (str[end] != ' ' && str[end] != '\0') end++;
            if (str[end] == '\0' && i != pattern.size()-1 || i == pattern.size()-1 && str[end] != '\0') return false;
            string temp = str.substr(start, end-start);
            start = end+1;
            if (map1.count(c) == 0) map1[c] = temp;
            if (map2.count(temp) == 0) map2[temp] = c;
            if (map1[c] != temp || map2[temp] != c) return false;
        }
        return true;
    }
};
