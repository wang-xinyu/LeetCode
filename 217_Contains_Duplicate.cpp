/**
 * Contains Duplicate
 */
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> map;
        for (int i : nums) {
            if (map[i]) return true;
            map[i] = true;
        }
        return false;
    }
};
