/**
 * The Skyline Problem
 */
class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> ans;
        multiset<pair<int, int>> criticalPoint;
        multiset<int> height({0});
        for (auto b : buildings) {
            criticalPoint.emplace(b[0], -b[2]);
            criticalPoint.emplace(b[1], b[2]);
        }
        int pre = 0;
        for (auto cp : criticalPoint) {
            if (cp.second < 0) height.insert(-cp.second);
            else height.erase(height.find(cp.second));
            if (*height.rbegin() != pre) {
                ans.push_back(make_pair(cp.first, *height.rbegin()));
                pre = *height.rbegin();
            }
        }
        return ans;
    }
};
