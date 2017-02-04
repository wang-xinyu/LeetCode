/**
 * Roman to Integer
 */
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romans = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int result = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            if (romans[s[i]] < romans[s[i+1]]) {
                result -= romans[s[i]];
            } else {
                result += romans[s[i]];
            }
        }
        return result;
    }
};
