/**
 * Different Ways to Add Parentheses
 *
 */
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> map;
        diffWaysToCompute(input, 0, input.size()-1, map);
        return map[input];
    }
private:
    void diffWaysToCompute(string &input, int l, int r, unordered_map<string, vector<int>>& map) {
        string str = input.substr(l, r-l+1);
        for (int i = l; i <= r; i++) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                string str1 = input.substr(l, i-l);
                string str2 = input.substr(i+1, r-i);
                if (map.count(str1) == 0) diffWaysToCompute(input, l, i-1, map);
                if (map.count(str2) == 0) diffWaysToCompute(input, i+1, r, map);
                for (auto a : map[str1]) {
                    for (auto b : map[str2]) {
                        switch (input[i]) {
                            case '+': map[str].push_back(a+b); break;
                            case '-': map[str].push_back(a-b); break;
                            case '*': map[str].push_back(a*b); break;
                        }
                    }
                }
            }
        }
        if (map.count(str) == 0) map[str].push_back(atoi(str.c_str()));
    }
};
